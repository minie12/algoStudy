#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int cnt = 1;
	int ans = 666;
	while(cnt < N){
		ans++;
		
		int check = ans;
		while(check > 0 ){
      // check if has 666 in the number
			if(check % 1000 == 666){
				cnt++;
				break;
			}
			else check /= 10;
		}
	}
	
	cout << ans;
	
	return 0;
}
