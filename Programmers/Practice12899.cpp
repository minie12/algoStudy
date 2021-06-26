// https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> num = {"4", "1", "2"};
    
    while(n > 1){
        int remainder = n % 3;
        n = n / 3;
        
        if(remainder == 0) n--;
        
        answer = num[remainder] + answer; 
    }
    if(n > 0) answer = num[n] + answer;
    
    return answer;
}
