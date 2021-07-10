//https://programmers.co.kr/learn/courses/30/lessons/67257

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long charCalc(char op, long long n1, long long n2){
    if(op == '+') return n1 + n2;
    else if(op == '*') return n1 * n2;
    else return n1-n2;
}

string opString(char a, char b, char c, string exp){
    string save = "";
    
    int index = 0;
    
    bool digit = false;
    
    string numb = "";
	numb += exp[index];
    while(isdigit(exp[++index])){ // get first number from expression
        numb += exp[index];
    }
    
    long long prev_numb = stoll(numb);
    
    while(index < exp.length()){
        string numb = "";
        while(exp[index] == a){
        	numb = exp[++index];
            while(isdigit(exp[++index])) numb += exp[index];

            prev_numb = charCalc(a, prev_numb, stoll(numb));
            digit = false;
        }
        if(digit || isdigit(exp[index])){  // if number
            numb = exp[index];
            while(isdigit(exp[++index])) numb += exp[index];
            
            prev_numb = stoll(numb);
            digit = false;
        }
        else if(exp[index] == b || exp[index] == c){  // if operator
            save += to_string(prev_numb) + exp[index++];
            digit = true;
        }
    }
    save += to_string(prev_numb);
        
    return save;
}

long long getCalc(char a, char b, char c, string exp){
    string exp2 = opString(a, b, c, exp);
    exp = opString(b, a, c, exp2);
    exp2 = opString(c, a, b, exp);

    return abs(stoll(exp2));    
}

long long solution(string expression) {
    long long answer = 0;
    string ops = "*+-";
    
    do{
        answer = max(answer, getCalc(ops[0],ops[1],ops[2],expression));
    }while(next_permutation(ops.begin(),ops.end()));
    
    return answer;
}
