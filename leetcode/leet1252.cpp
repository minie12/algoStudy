// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int mat[50][50] = {0};
        
        int ans = 0;
        for(vector<int> ind : indices){
            for(int i = 0; i < n; i++){
                mat[ind[0]][i]++;
                if(mat[ind[0]][i] % 2 == 0) ans--;
                else ans++;
            }
            for(int i = 0; i < m; i++){
                mat[i][ind[1]]++;
                if(mat[i][ind[1]] % 2 == 0) ans--;
                else ans++;
            }
        }
        
        return ans;
    }
};
