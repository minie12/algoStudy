// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {   
    unordered_map<string, int> map;
    vector<string> dict;
    
    for(string key : phone_book){
        string temp = "";
        for(int i =0; i < key.length(); i++){
            temp += key[i];
            map[temp]++;
        }
    }
    
    for(string key : phone_book){
        if(map[key] > 1) return false;
    }

    return true;
}
