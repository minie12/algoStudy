// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int cnt = 0;
            
            int numb = i;
            while(numb > 0){
                if(numb%2 == 1) cnt++;
                numb = numb/2;
            }
            
            ans.push_back(cnt);
        }    
        
        return ans;
    }
};
