#include <iostream>

using namespace std;

int fibo(int n){
	if(n == 1) return 1;
	if(n == 0) return 0;
	
	return fibo(n-2) + fibo(n-1);
}

int main(){
	int N; cin >> N;
	cout << fibo(N);
}
