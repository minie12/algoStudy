#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    if(k < food_times.size()) return k+1;
    
    priority_queue<pair<int,int>> foods;
    
    long long tot = 0;
    for(int i = 0; i < food_times.size(); i++){
        tot += food_times[i];
        foods.push(make_pair(-food_times[i],i+1));
    }
    if(tot <= k) return -1; // no food left before k
    
    int prev = 0;
    while(!foods.empty() && (-foods.top().first+prev)*foods.size() <= k ){
        k -= (-foods.top().first+prev)*foods.size();
        prev = foods.top().first;
        foods.pop();
    }
    
    vector<int> ans;
    while(!foods.empty()){
        ans.push_back(foods.top().second);
        foods.pop();
    }
    sort(ans.begin(), ans.end());
    
    return ans[k%ans.size()];
}
