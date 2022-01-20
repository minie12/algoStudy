#include <iostream>
#include <string>

using namespace std;

int main(){
	string N;
	cin >> N;
	
	int ans = 0;
	
	for(int i = 0; i < N.length(); i++){
		int num = N[i] - 48;
		if(num <= 1 || ans <= 1) ans += num;
		else ans *= num;
	}
	
	cout << ans;
	
	
	return 0;
}
