#include <iostream>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		int min = 10001;
		for(int j  = 0; j < M; j++){
			int card;
			cin >> card;
			if(min > card) min = card;
		}
		
		if(min > ans) ans = min;
	}
	
	cout << ans;
	
	return 0;
}
