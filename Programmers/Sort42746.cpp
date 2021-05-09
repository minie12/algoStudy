// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> numb_list;
    
    for(int i = 0; i < numbers.size(); i++){
        numb_list.push_back(to_string(numbers[i]));
    }
    
    sort(numb_list.begin(), numb_list.end(), compare);
    
    if(numb_list[0] == "0") return "0";
    
    for(int i = 0; i <numb_list.size(); i++){
        answer += numb_list[i];
    }
    
    return answer;
}
