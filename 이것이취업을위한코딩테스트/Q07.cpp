#include <iostream>
#include <string>

using namespace std;

int main(){
	string N;
	cin >> N;
	
	int left = 0;int right = 0;
	int mid = N.length()/2;
	
	for(int i = 0; i < N.length(); i++){
		if(i >= mid) right += N[i];
		else left += N[i];
	}
	
	if(right == left) cout << "LUCKY";
	else cout << "READY";
	
	return 0;
}
