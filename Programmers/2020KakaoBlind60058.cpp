//https://programmers.co.kr/learn/courses/30/lessons/60058

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkCorrect(string s){
    stack<char> check;
    for(char b : s){
        if(b == '(') check.push('(');
        else{
            if(check.empty()) return false;
            else  check.pop();
        }
    }
    
    return true;
}

string flipBracket(string s){
    string flipped = "";
    
    for(int i = 1; i < s.length()-1; i++){
        if(s[i] == '(') flipped.push_back(')');
        else flipped.push_back('(');
    }
    
    return flipped;
}

string bracChange(string p){    
    int start = 0;
    int left = 0, right = 0;
    
    for(int idx = 0; idx < p.length(); idx++){
        if(p[idx] == '(') right++;
        else left++;
        
        if(left == right){
            string u = p.substr(start, idx-start+1);
            string v = p.substr(idx+1);
            
            if(checkCorrect(u)) return u+bracChange(v);
            else{
                return "(" + bracChange(v) + ")" + flipBracket(u);
            }
        }
    }
    
    return "";
}

string solution(string p) {
    string answer = bracChange(p);
    
    return answer;
}
