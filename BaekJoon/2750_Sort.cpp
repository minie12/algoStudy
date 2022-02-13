#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;

    vector<int> nums;
    for(int i = 0; i < N; i++){
        int n; cin >> n;
        nums.push_back(n);
    }
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < N; i++) cout << nums[i] << endl;
    return 0;
}
