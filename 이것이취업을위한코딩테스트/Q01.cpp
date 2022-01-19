#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	vector<int> stats;
	
	for(int i = 0 ; i < N; i++){
		int x; cin >> x;
		stats.push_back(x);
	}
	
	sort(stats.begin(), stats.end());
	
	int ans = 0;
	while(stats.size() > 0){
		int cnt = 0;
		int i = N-1;
		while(i > -1){
			if(i - stats[i] <= N){
				cnt++;
				i -= stats[i];
			}
			else break;
		}
		
		stats.pop_back();
		
		if(ans < cnt) ans = cnt;
		else break;
	} 
	
	
	cout << ans;
	
	
	return 0;
}
