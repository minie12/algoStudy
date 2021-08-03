// https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for(int cut = 1; cut <= s.length()/2; cut++){        
        int cnt = 1;
        string comp = s.substr(0,cut);
        string temp = "";
        int idx;
        for(idx = cut; idx+cut <= s.length(); idx += cut){
            if(comp == s.substr(idx,cut)) cnt++;
            else{
                if(cnt != 1) temp += to_string(cnt);
                temp += comp;
                comp = s.substr(idx,cut);
                cnt = 1;
                
                if(temp.length() > answer) break;
            }
        }
        
        if(cnt != 1) temp += to_string(cnt);
        temp += s.substr(idx-cut, s.length()-idx+cut);
        
        answer = min(int(temp.length()), answer);
    }
    
    return answer;
}
