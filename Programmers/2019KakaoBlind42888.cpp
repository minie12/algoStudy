// https://programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, ' ')) {
        internal.push_back(temp);
    }
 
    return internal;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> pre_answer;
    
    unordered_map<string, string> nickname;
    
    for(string rec : record){
        vector<string> sp_rec = split(rec);
        
        if(sp_rec[0] == "Enter") {
            nickname[sp_rec[1]] = sp_rec[2];
            pre_answer.push_back(sp_rec[1]+"_E");
        }
        else if(sp_rec[0] == "Change") nickname[sp_rec[1]] = sp_rec[2];
        else if(sp_rec[0] == "Leave"){
            pre_answer.push_back(sp_rec[1]+"_L");
        }
    }
    
    for(string rec : pre_answer){
        int i = 0;
        string id = "";
        while(rec[i] != '_'){
            id += rec[i++];
        }
        if(rec[1+i] == 'L') answer.push_back(nickname[id] + "님이 나갔습니다.");
        else if(rec[1+i] == 'E') answer.push_back(nickname[id] + "님이 들어왔습니다.");
    }
    
    return answer;
}
