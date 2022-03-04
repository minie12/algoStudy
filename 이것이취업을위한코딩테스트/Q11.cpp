#include <iostream>
#include <queue>

using namespace std;

int GetDirection(char D, int i){
	if(D == 'L') i -= 1; // turn CCW
	else i += 1; // turn CW
	
	if(i < 0) i = 3;
	
	return i%4; 
}

void printBoard(int board[101][101], int N){
	for(int i = 1; i < N+1; i++){
		for(int j = 1; j < N+1; j++){
			if(board[i][j] == -1) cout << 8 << " ";
			else cout << board[i][j] << " ";
		}
		
		cout << endl;
	}
	cout << endl;
}

int main(){
	int N, K; // map size, apple count
	cin >> N >> K;
	
	int board[101][101]; 
	board[1][1] = -1; // have snake body
	
	for(int i = 0; i < K; i++){
		int a1, a2;
		cin >> 	a1 >> a2;
		board[a2][a1] = 1; // have apple
	}
	
	// direction {R, D, L, U}
	int dy[4] = {1, 0, -1, 0};
	int dx[4] = {0, 1, 0, -1};
	
	int L; // direction count
	cin >> L;
	queue<pair<int, char>> turns;
	for(int i = 0; i < L; i++){
		int x; char c;
		cin >> x >> c;
		turns.push({x,c});
	}
	
	// direction
	char c;
	queue<pair<int,int>> snake;
	snake.push(make_pair(1,1));
	int d_h = 0;
	
	// time
	int time = 0;
	while(true){
		time++; 
		
		int h_x = snake.back().first + dx[d_h];
		int h_y = snake.back().second + dy[d_h];
		
		//cout << "time: " << time << "(" << h_x << ", " << h_y << ")" << endl;
			
		// if head meets wall
		if(h_x > N || h_y > N || h_x < 1 || h_y < 1 || board[h_y][h_x] == -1) break;
			
		if(board[h_y][h_x] != 1){ // don't have apple
			int t_x = snake.front().first;
			int t_y = snake.front().second;
			snake.pop();
			board[t_y][t_x] = 0;
		}
		
		snake.push(make_pair(h_x, h_y));
		board[h_y][h_x] = -1;
		
		//printBoard(board, N);
		
		// get next direction
		if(time >= turns.front().first && turns.size()!=0){
			d_h = GetDirection(turns.front().second, d_h);
			turns.pop();
		}
	}

	cout << time;
	
	
	return 0;
}
