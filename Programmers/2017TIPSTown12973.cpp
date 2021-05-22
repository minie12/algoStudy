//https://programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    if(s.length()%2 != 0) return 0; // if odd number, cannot erase all
    
    stack<char> str;
    
    for(char ch : s){
        if(str.empty()) str.push(ch);
        else{
            char back = str.top();
            if(back == ch) str.pop();
            else str.push(ch);
        }
    }
    
    if(str.empty()) return 1;
    
    return 0;
}
