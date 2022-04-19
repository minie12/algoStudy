// https://programmers.co.kr/learn/courses/30/lessons/60058

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string flipBrackets(string p){
	string res;
	for(int i = 1; i < p.length()-1; i++){
		if(p[i] == '(') res += ")";
		else res += "(";
	}
	return res;
}

bool checkBrackets(string p){
	stack<char> brackets;
	for(char c : p){
		if(c == '(') brackets.push('(');
		else{
			if(brackets.empty()) return false; // no matching '(';
			
			brackets.pop();
		}
	}
	
	if(!brackets.empty()) return false; // no matching ')'
	return true;
}

string solution(string p){
	string ans;
	
	string u, v;
	int open = 0, close = 0;
	for(char c : p){
		if(c == '(') open++;
		else close++;
		
		u += c;
		if(open == close){
			string v = p.substr(u.length());
			
			if(checkBrackets(u)){
				ans += u;
				// do the same step to v
				if(v.length()) ans += solution(v);
			}
			else{
				ans += "(" + solution(v) + ")" + flipBrackets(u);
			}
			break; // since the rest of string p is already checked in the if/else statement
		}
	}
	
	return ans;
}
