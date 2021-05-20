//https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <algorithm>

#define isCapital(x) ((x) >= 'A' && (x) <= 'Z')
#define isLetter(x) ((x) >= 'a' && (x) <='z')
#define isDigit(x) ((x) >= '0' && (x) <= '9')

using namespace std;

string solution(string new_id) {
    vector<char> symbol = {'-', '_', '.'};
    
    string answer = "";
    
    int i = 0;
    while(i < new_id.length()){
        char letter = new_id.at(i);
        // #1. Upper to Lowercase
        if(isCapital(letter)) answer += letter+32;
        // #2. leave lowercase and digits
        else if(isLetter(letter) || isDigit(letter)) answer += letter;
        // #2, 3. Remove other symbols and remove repeating '.'
        else if(find(symbol.begin(), symbol.end(), letter) != symbol.end()){
            if(letter == '.'){
                while(i+1 < new_id.length() && new_id.at(i+1) == '.'){
                    i++;
                }
                if(answer.back() != '.') answer += '.';
            }
            else{
                answer += letter;
            }
        }
        // #5. insert 'a' into blank space
        else if(letter == ' ') answer += 'a';
        
        i++;
    }
    
    // #4. remove first and last '.'
    while(answer.length() > 0 && answer.at(0) == '.')answer = answer.substr(1);
    while(answer.length() > 0 && answer.back() == '.') answer.pop_back();
    
    // #6. set id length as 15
    if(answer.length() > 15){
        answer = answer.substr(0, 15);
        if(answer.back() == '.') answer.pop_back();
    }
    else if(answer.length() <= 2){
        char last = 'a';
        if(answer.length() != 0) last = answer.back();
        while(answer.length() < 3) answer += last;
    }
    
    return answer;
}
