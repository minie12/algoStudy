#include <iostream>
#include <string>

using namespace std;

int main(){
	string N;
	cin >> N;
	
	bool cont = false;
	int cnt0 = 0, cnt1 = 0;
	if(N[0] == '0') cnt0 = 1;
	for(int i = 0; i < N.length(); i++){
		if(N[i] == '1'){
			if(!cont){
				cnt1++;
				cont = true;
			} 
		}
		else{
			if(cont) cnt0++;
			cont = false;
		}
	}
	
	int ans = min(cnt0, cnt1);
	
	cout << ans;
	
	return 0;
}
