// https://leetcode.com/problems/unique-number-of-occurrences/ 

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool answer = true;
        
        sort(arr.begin(), arr.end());
        
        int cnt = 0;
        vector<int> counts;
        
        int prev = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(prev!=arr[i]){
                if(find(counts.begin(), counts.end(), cnt) == counts.end()){
                    counts.push_back(cnt);
                    cnt = 0;
                    prev = arr[i];
                    continue;
                }
                cout<< "Was not same" << endl;
                
                answer = false;
                break;
            }
            
            cnt++;
        }
        
        if(find(counts.begin(), counts.end(), cnt) != counts.end()) return false;
        
        return answer;
    }
};
