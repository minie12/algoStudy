// https://programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    
    // init dictionary
    char c = 'A';
    for(int i = 1; i < 27; i++){
    	string s;
    	s.append(1, c);
        dict[s] = i;
        c = c+1;
    }
    int dict_last = 26;
    
    // encode
    int idx = 0;
    string key = "";
    int dict_sec = -1;
    while(idx < msg.length()){
        key += msg[idx];
        
        if(dict.find(key) != dict.end()){
            dict_sec = dict[key];
            idx++;
        }
        else{
            dict[key] = ++dict_last;
            answer.push_back(dict_sec);
            key = "";
        }
    }
    answer.push_back(dict_sec);
    
    return answer;
}
