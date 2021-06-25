// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> closet;
    
    for(int i = 0; i < clothes.size(); i++){
        if(closet.count(clothes[i][1])) closet[clothes[i][1]]++;
        else closet[clothes[i][1]] = 2; // to include "not wearing"
    }
    
    for(auto key : closet){
        answer *= key.second;
    }
    
    return answer-1;
}
