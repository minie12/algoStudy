#include <iostream>

using namespace std;

int main(){
	int N;

	cin >> N;
	
	int ans[50];
	int data[50][2];
	
	for(int i = 0; i < N; i++){
		int weight, height;
		cin >> weight >> height;
		
		data[i][0] = weight;
		data[i][1] = height;
	} 
	
	for(int i = 0; i < N; i++){
		ans[i] = 1;
		for(int j = 0; j < N; j++){
			if(i == j) continue; // if same person, pass
			
			if(data[i][0] < data[j][0] && data[i][1] < data[j][1]) ans[i]++;
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
