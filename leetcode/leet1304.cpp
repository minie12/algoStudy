//https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2 != 0){
            ans.push_back(0);
            for(int i = 0; i < n/2; i++){
                ans.push_back(-n+i);
                ans.push_back(n-i);
            }
        }
        else{
            for(int i = 0; i < n/2; i++){
                ans.push_back(-n+i);
                ans.push_back(n-i);
            }
        }
        return ans;
    }
};
