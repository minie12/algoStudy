// https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> save;
    
    for(int i = 0; i < priorities.size(); i++) save.push(i);
    
    while(!save.empty()){
        int index = save.front();
        save.pop();
        
        if(priorities[index] != *max_element(priorities.begin(), priorities.end())){
            save.push(index);
        }
        else{
            answer++;
            if(index == location) return answer;
            
            priorities[index] = 0;
        }
    }
    
    return -1;
}
