#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ans = 0;
int N, M;

void SpreadVirus(vector<vector<int>> &map){
	queue<pair<int, int>> virus;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 2) virus.push({i,j});
		}
	}
	
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	
	while(!virus.empty()){
		int x_ = virus.front().first;
		int y_ = virus.front().second;
		virus.pop();
		
		for(int i = 0; i < 4; i++){
			int x = x_ + dx[i];
			int y = y_ + dy[i];
			if(x >=0 && x < N && y >=0 && y < M){
				if(map[x][y] == 0){
					virus.push({x,y});
					map[x][y] = 2;
				}
			}
		}	
	}
}

void BuildWall(vector<vector<int>> map, int x, int y, int cnt){
	map[x][y] = 1;
	
	if(cnt == 3){
		SpreadVirus(map);
		
		int score = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j] == 0) score++;
			}
		}
		
		if(score > ans) ans = score;
		
		return;
	} 
	
	for(int i = x; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 0) BuildWall(map, i, j, cnt+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	vector<vector<int>> map;
	
	for(int i = 0; i < N; i++){
		vector<int> t;
		for(int j = 0; j < M; j++){
			int x;
			cin >> x;
			t.push_back(x);
		}
		map.push_back(t);
		t.clear();
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 0) BuildWall(map, i, j, 1);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
