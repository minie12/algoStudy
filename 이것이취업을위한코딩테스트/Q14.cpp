#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size()+1;
    
    // make circle wall to straight path
    int w_size = weak.size();
    if(w_size == 0) return 0; // check if there is no weak point
    for(int i = 0; i < w_size; i++){
        weak.push_back(n + weak[i]);                                
    }
    
    // nPr
    do {
        for(int i = 0; i < w_size; i++){
            int cnt = 1;
            int pos = weak[i] + dist[cnt-1];
            for(int k = i; k < i+w_size; k++){
                if(weak[k] > pos) {
                    cnt++;
                    if(cnt > dist.size()) break;
                    if(cnt > answer) break;
                    pos = weak[k] + dist[cnt-1];
                }
            }
            if(cnt < answer) answer = cnt;
        }
	} while(next_permutation(dist.begin(), dist.end()));
    
    if(answer > dist.size()) return -1; // cannot achieve at any state
    
    return answer;
}
