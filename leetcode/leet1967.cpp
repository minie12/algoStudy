// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        vector<string> sub;
        int ans = 0;
        
        for(string s : patterns){
            if(find(sub.begin(), sub.end(), s) != sub.end()) ans++;
            else if(word.find(s) != string::npos){
                sub.push_back(s);
                ans++;
            }
        }
        
        return ans;
    }
};
