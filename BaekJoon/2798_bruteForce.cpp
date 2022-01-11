#include <iostream>

using namespace std;

int main(){
	int N, MAX;

	cin >> N >> MAX;
	
	int data[N];
	int ans = 0;
	
	int x;
	for(int i = 0; i < N; i++){
		cin	>> x;
		data[i] = x;
	}
	
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			for(int k = j+1; k < N; k++){
				int sum = data[i] + data[j] + data[k];
				
				if(sum <= MAX && sum > ans) ans = sum;			
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
