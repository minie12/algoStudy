#include <iostream>
#include <string>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	string board[50];
	
	for(int i = 0; i < N; i++){
		cin >> board[i];
	} 
	
	int ans = 2500;
	char W[2] = {'W','B'};
	
	for(int i = 0; i <= N-8; i++){
		for(int j = 0; j <= M-8; j++){
			
			int flipCntW=0;
			int flipCntB=0;
			for(int x = 0; x < 8; x++){
				for(int y = 0; y < 8; y++){
					// left-right is W
					if(board[i+x][j+y] != W[(i+x+j+y)%2]) flipCntW++;
					// left-right is B 
					if(board[i+x][j+y] != W[(i+x+j+y+1)%2]) flipCntB++;
				}
			}
			
			ans = min(ans, min(flipCntW, flipCntB));
		}
		if(ans == 0) break;
	}
	
	cout << ans;
	
	return 0;
}
