// https://leetcode.com/problems/count-of-matches-in-tournament/

class Solution {
public:
    int numberOfMatches(int n) {
        int tot = 0;
        
        while(n > 1){
            tot += n/2;
            n = n%2==0? n/2 : n/2+1;
        }
        
        return tot;
    }
};
