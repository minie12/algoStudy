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
		board[a1][a2] = 1; // have apple
	}
	
	// direction {R, D, L, U}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	int L; // direction count
	cin >> L;
	int time = 1;
	
	// direction
	char c;
	queue<pair<int,int>> snake;
	snake.push(make_pair(1,1));
	int d_h = 0;
	
	// time
	int x, i = 1; 
	cin >> x >> c;
	while(true){
		int h_x = snake.back().first + dx[d_h];
		int h_y = snake.back().second + dy[d_h];
		
		cout << "time: " << time << "(" << h_x << ", " << h_y << ")" << endl;
			
		// if head meets wall
		if(h_x > N || h_y > N || h_x < 1 || h_y < 1) break;
		
		if(board[h_y][h_x] == 1){ // have apple
			snake.push(make_pair(h_x, h_y));
			board[h_y][h_x] = -1;
		}
		else{
			if(board[h_y][h_x] == -1){ // have body
				break;
			}
			
			snake.push(make_pair(h_x, h_y));
			board[h_y][h_x] = -1;
			
			int t_x = snake.front().first;
			int t_y = snake.front().second;
			snake.pop();
			board[t_y][t_x] = 0;
		}
		
		printBoard(board, N);
		
		// get next direction
		if(time >= x && i <= L){
			d_h = GetDirection(c, d_h);
			
			if(i < L) cin >> x >> c;
			
			i++;
		}
		
		time++;
	}

	cout << time;
	
	
	return 0;
}
