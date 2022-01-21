#include <iostream>
#include <algorithm>

using namespace std;

bool summation(int *coin, int idx, int sum, int goal){
	if(sum == goal) return true;
	if(sum + coin[idx] > goal) return false;
	
	bool x1 = summation(coin, idx+1, sum, goal);
	bool x2 = summation(coin, idx+1, sum+coin[idx],goal);

	return (x1 || x2);
}

int main(){
	int N;
	cin >> N;
	
	int coin[1000];
	int max = 0;
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		coin[i] = x;
		max += x;
	}
	
	sort(coin, coin + N);
	
	int ans = 1;
	while(ans <= max){
		if(summation(coin, 0, 0, ans)) ans++;
		else break;
	}
	
	cout << ans;
	
	
	return 0;
}
