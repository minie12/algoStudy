// https://programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int length = s.length();
    
    if(length == 1){
        return s;
    }
    
    if(length % 2 == 0){
         answer = s.at(length/2-1);
         answer += s.at(length/2);
    }
    else{
        answer = s.at(length/2);
    }
    
    return answer;
}
