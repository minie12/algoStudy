// https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    vector<int> taken; // index of taken shirts
    
    // check if reserve and lost has duplicate number
    for(int i = 0; i < reserve.size(); i++){
        auto it = find(lost.begin(), lost.end(), reserve[i]);
        if(it != lost.end()){
            int index = it-lost.begin();
            lost.erase(lost.begin()+index);
            taken.push_back(i);  
            answer++;
        }
    }
    
    for(int i : lost){
        auto it = find(reserve.begin(), reserve.end(), i-1);
        if(it != reserve.end()){
            int index = it-reserve.begin();
            // if shirt not already taken
            if(find(taken.begin(), taken.end(), index) == taken.end()){
                taken.push_back(index); 
                answer++;
                continue;
            }
        }
        it = find(reserve.begin(), reserve.end(), i+1);
        if(it != reserve.end()){
            int index = it-reserve.begin();
            // if shirt not already taken
            if(find(taken.begin(), taken.end(), index) == taken.end()){
                taken.push_back(index); 
                answer++;
            }
        }
    }
    
    
    return answer;
}
