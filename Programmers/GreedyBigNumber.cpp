//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;

int bigNumb(string number){
    int max = 0;
    int max_idx = -1;
    for(int i = 0; i < number.length(); i++){
        int numb = number[i] - '0';
        if(max < numb){
            max = numb;
            max_idx = i;
        }
        if(numb == 9) break;
    }
    
    return max_idx * 10 + max;
}

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    
    while(k > 0 && index < number.length()){
        int idxNmax = bigNumb(number.substr(index,k+1));
        int idx = idxNmax / 10;
        int max = idxNmax % 10;        
        
        k -= idx;
        index += idx+1;
        
        answer += to_string(max);
        while(number[index] - '0' == 9){
            answer += "9";
            index++;
        }
    }
        
    for(int i = index; i < number.length(); i++) answer += number[i];
    
    if(k > 0){
        answer = answer.substr(0, number.size()-k);
    }
    
    return answer;
}
