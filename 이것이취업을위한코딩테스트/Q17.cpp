// https://www.acmicpc.net/problem/18405

#include <iostream>
#include <queue>

using namespace std;

struct virusInfo{
	int time, virus, x, y;
	virusInfo(int T, int V, int X, int Y) : time(T), virus(V), x(X), y(Y) {}
};

bool operator < (virusInfo a, virusInfo b){
	if(a.time == b.time) return a.virus > b.virus; // so that smaller value has higher priority
	return a.time > b.time; // so that smaller value has higher priority
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	int map[201][201];
	priority_queue<virusInfo> virus;
	
	for(int i = 1; i < N+1; i++){
		for(int j = 1; j < N+1; j++){
			int x;
			cin >> x;
			map[i][j] = x;
			// when virus found, save info
			if(x != 0) virus.push(virusInfo(0, x, i, j));
		}
	}
	
	int S, X, Y;
	cin >> S >> X >> Y;

	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	
	
	int time = 0; 
	while(!virus.empty()){
		virusInfo v = virus.top(); virus.pop();
		
		time = v.time;
		if(time >= S) break;
		
		for(int i = 0; i < 4; i++){
			int x = v.x + dx[i];
			int y = v.y + dy[i];
			if(x > 0 && x < N+1 && y > 0 && y < N+1){
				if(map[x][y] == 0){
					map[x][y] = v.virus;
					virus.push(virusInfo(time+1, v.virus, x, y));
				}
			}
		}
	}
	
	cout << map[X][Y] << endl;
	
	return 0;
}
