// https://programmers.co.kr/learn/courses/30/lessons/12922

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int repeat = n/2;
    for(int i = 0; i < repeat; i++) answer += "수박";
    
    if(n%2 == 1) answer += "수";
    
    return answer;
}
