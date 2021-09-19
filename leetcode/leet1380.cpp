// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        bool lucky = true;
        
        for(int i = 0; i < matrix.size(); i++){
            lucky = true;
            int min = 100000;
            int min_idx = 0;
            for(int j = 0; j < matrix[0].size(); j++){
                if(min > matrix[i][j]) {
                    min = matrix[i][j];
                    min_idx = j;
                }
            }
            
            for(int k = 0; k < matrix.size(); k++){
                if(i == k) continue;
                if(matrix[k][min_idx] > min){
                    lucky = false;
                    break;
                }
            }
            
            if(lucky) ans.push_back(min);
        }
        
        return ans;
    }
};
