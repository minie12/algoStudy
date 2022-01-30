#include <iostream>
#include <string>

using namespace std;

int main(){
	string N;
	cin >> N;
	
	int ans = N.length();
	for(int i = 1; i <= N.length()/2; i++){
		string s = "";
		string check = N.substr(0, i);
		int cnt = 1;
		int j;
		for(j = i; j+i <= N.length(); j+=i){
			string next = N.substr(j, i);
			if(check == next) cnt++;
			else{
				if(cnt!=1) s += to_string(cnt);
				s += check;
				
				check = next;
				cnt = 1;
				
				if(s.length() > ans) break;
			}
		}
		
		if(cnt!=1) s += to_string(cnt);
		s += N.substr(j-i, N.length()-j+i);
		
		if(ans > s.length()) ans = s.length();
	}
	
	cout << ans;
	
	return 0;
}
