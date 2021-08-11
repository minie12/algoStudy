// https://programmers.co.kr/learn/courses/30/lessons/17677

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int swap_vec(vector<string> &s, int ind1, int ind2){
    string temp = s[ind1];
    s[ind1] = s[ind2];
    s[ind2] = temp;
    
    return 0;
}

int solution(string str1, string str2) {
    vector<string> s1,s2;
    
    int cnt = 0;
    int idx = 0;
    while(idx+1 < str1.length() || idx+1 < str2.length()){
        if(idx+1 < str1.length()){
            if(isalpha(str1[idx]) && isalpha(str1[idx+1])) {
                string s = str1.substr(idx,2);
                for_each(s.begin(), s.end(), [](char & c){c = ::tolower(c);});
                
                s1.push_back(s);
                cnt++;
            }
        }
        
        if(idx+1 < str2.length()){
            if(isalpha(str2[idx]) && isalpha(str2[idx+1])) {
                string s = str2.substr(idx,2);
                for_each(s.begin(), s.end(), [](char & c){c = ::tolower(c);});
                
                s2.push_back(s);
                cnt++;
            }
        }
        
        idx++;
    }
    
    if(cnt == 0) return 65536;
    
    int same = 0;
    for(int i = 0; i < s1.size(); i++){
        for(int j = same; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                swap_vec(s2, same, j);
                same++;
                break;
            }
        }
    }
    
    return long(double(same)*65536/(cnt-same));
}
