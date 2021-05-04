// https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> map;
    
    for(int i = 0; i < participant.size(); i++){
        // if contains participant name
        if(map.find(participant[i]) != map.end()) map[participant[i]]++;
        // if no, create one
        else map[participant[i]] = 1;
    }
    
    for(int i = 0 ; i < completion.size(); i++){
        // if contains completion name
        if(map.find(completion[i]) != map.end()) map[completion[i]]--;
    }
    
    for(pair<string,int> key: map){
        if(key.second > 0) return key.first;
    }
    
    return answer;
}
