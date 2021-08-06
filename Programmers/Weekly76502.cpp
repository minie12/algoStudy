// https://programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    vector<char> par;
    for(int i = 0; i < len; i++) par.push_back('n');
    
    for(int cnt = 0; cnt < len; cnt++){
        int idx = 0;
        bool flag = true;
        for(int i = 0; i < len; i++){
            if(s[(cnt+i)%len] == '[' || s[(cnt+i)%len] == '(' || s[(cnt+i)%len] == '{') par[idx++] = s[(cnt+i)%len];
            else{
                if(idx-1 == -1) {
                    flag = false;
                    break;
                }
                if(par[--idx] == '[' && s[(cnt+i)%len] == ']') continue;
                else if(par[idx] == '{' && s[(cnt+i)%len] == '}') continue;
                else if(par[idx] == '(' && s[(cnt+i)%len] == ')') continue;
                
                // parantheses does not match
                flag = false;
                break;
            }
        }
        
        // check idx as well in case only [({ is given as s
        if(flag && idx == 0){
            answer++;
        }
    }
    
    return answer;
}
