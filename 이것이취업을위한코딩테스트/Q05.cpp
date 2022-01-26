#include <iostream>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	int weights[1000];
	
	int ans = 0;
	
	for(int i = 0; i < N; i++){
		int w;
		cin >> w;
		weights[i] = w;
		
		for(int j = 0; j < i; j++){
			if(weights[j] != w) ans++;
		}		
	}

	cout << ans;
	
	return 0;
}
