#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	string n; cin >> n;
	
	vector<int> nums; 
	for(int i = 0; i < n.length(); i++) nums.push_back(n[i]-'0');
	
	sort(nums.begin(), nums.end(), greater<int>());
	
	for(int i = 0; i < n.length(); i++) cout << nums[i];
	return 0;
}
