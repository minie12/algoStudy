// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int alpha[26] = {0};
        
        for(char c : s){
            alpha[c - 97]++;
        }
        
        int idx = 0;
        for(int i = 0; i < 26; i++){
            if(alpha[i] != 0){
                idx = i;
                break;
            }
        }
        for(int i = idx+1; i < 26; i++){
            if(alpha[i] == 0) continue;
            if(alpha[i] != alpha[idx]) return false;
        }
        
        return true;
    }
};
