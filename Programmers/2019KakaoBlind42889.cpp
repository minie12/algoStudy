//https://programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,float> a, pair<int,float> b){
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> record;
    vector<pair<int,float>> fault;

    // init record
    for(int i = 0; i < N+1; i++){
        record.push_back(0);
    }
    
    // count how many reached the stage
    for(int i = 0; i < stages.size(); i++){
        record[stages[i]-1] += 1;
    }
     
    int total = stages.size();
    for(int i = 0; i < N; i++){
        int failed = record[i];
        if(total == 0) fault.push_back(make_pair(i+1,0));
        else fault.push_back(make_pair(i+1,failed/double(total)));
        total -= failed;
    }
    
    sort(fault.begin(),fault.end(),compare);
    
    for(int i = 0; i < N; i++){
    	answer.push_back(fault[i].first);
	}
    
    return answer;
}
