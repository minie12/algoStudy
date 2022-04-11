#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[300001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	
	int N, M, K, X; // num of city, n of road, shortest dist, starting city
	cin >> N >> M >> K >> X;
	
	//init
	for(int i = 0; i < N; i++) visited[i] = false;
	
	vector<int> ans;
	vector<vector<int>> roadmap(N+1);
	
	// get map data into vector
	for(int i = 0; i < M; i++){
		int start, end;
		cin >> start >> end;
		roadmap[start].push_back(end);			
	}
	
	// bfs - check shortest dist first
	queue<pair<int,int>> route;  
	route.push({X, 0});
	visited[X] = true;
	
	while(!route.empty()){
		int city = route.front().first;
		int weight = route.front().second;
//		tie(city, weight) = route.front();
		route.pop();
		
		if(weight == K) ans.push_back(city);
		for(int i = 0; i < (signed)roadmap[city].size(); i++){
			int v = roadmap[city][i];
			if(!visited[v]){
				visited[v] = true;
				route.push({v, weight+1});
			}
		}
	}
	
	if(ans.size() == 0) cout << -1 << endl;

	sort(ans.begin(), ans.end());
	for(int a : ans) cout << a << endl;
	
	return 0;
}
