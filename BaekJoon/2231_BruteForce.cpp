#include <iostream>

using namespace std;

int main(){
	int N;

	cin >> N;
	
	int ans = 0;
	
	// as N is 1 <= N <= 1 000 000
	// biggest answer possible is 999 999, which adds up to 54
	for(int i = N-54; i < N; i++){
		int sum = i;
		int x = i;
		while(x > 0){
			sum+= x%10;
			x /= 10;
		}
		
		if(sum == N){
			ans = i;
			break;
		}
	} 
	
	cout << ans;
	
	return 0;
}
