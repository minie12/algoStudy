#include <iostream>
#include <string>

using namespace std;

int main(){
	string N;
	cin >> N;
	
	int num = 0;
	string ans;
	for(int i = 0; i < N.length(); i++){
		if(isdigit(N[i])) num += N[i]-48;
		else{
			// string: sort in alphabetical order
			if(ans.length() == 0) ans += N[i];
			else{
				int j = 0; 
				for(j = 0; j < ans.length(); j++){
					if(ans[j] > N[i]) {
						ans.insert(j, 1, N[i]);
						break;
					}
				}
				if(j == ans.length()) ans += N[i];
			} 
		} 
	}
	
	cout << ans << num;
	
	return 0;
}
