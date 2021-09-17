// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates2(string s) {
        vector<char> dup;

        for(int i = 0; i < s.length(); i++){
            if(dup.empty()) dup.push_back(s[i]);
            else{
                if(dup.back() == s[i]) dup.pop_back();
                else dup.push_back(s[i]);
            }
        }
        
        string ans = "";
        for(int i = 0; i < dup.size(); i++) ans+=dup[i];
        
        return ans;
    }
    
    // take less time (referenced in discussion)
    string removeDuplicates(string s) {
        int idx = 0;
        for(int i = 1; i < s.length(); i++){
            if(idx < 0 || s[idx] != s[i]) s[++idx] = s[i];
            else --idx;
        }
        return s.substr(0, idx+1);
    }
};
