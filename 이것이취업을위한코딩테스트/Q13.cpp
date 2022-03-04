//https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int ans = 987654321;

int ChickDist(vector<pair<int,int>> &homes, vector<pair<int,int>> &select){
	int sum = 0;
	for(int i = 0; i < homes.size(); i++){
		int h_x = homes[i].first;
		int h_y = homes[i].second;
		
		int min = 987654321;
		for(int j = 0; j < select.size(); j++){
			int dist = abs(h_x-select[j].first) + abs(h_y-select[j].second);
			
			if(dist < min) min = dist;
		}	
		sum += min;
		if(sum > ans) break;
	}
	
	return sum;
}

void Select(vector<pair<int,int>> &chickens, vector<pair<int,int>> &homes, vector<pair<int,int>> &select, int idx, int cnt, int M){
	if(cnt == M){
		int sum = ChickDist(homes, select);
		if(sum < ans) ans = sum;
	}
	
	// select chicken by combination (nCr)
	for(int i = idx; i < chickens.size(); i++){
		select.push_back(chickens[i]);
		Select(chickens, homes, select, i+1, cnt+1, M);
		select.pop_back();
	}	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N, M; cin >> N >> M;
	
	vector<pair<int, int>> chickens;     // (x, y)
	vector<pair<int, int>> homes;     // (x, y)
	
	// get map data
	for(int i = 1; i < N+1; i++){
		for(int j = 1; j < N+1; j++){
			int x; cin >> x;
			
			if(x == 1) homes.push_back(make_pair(j,i));
			else if(x == 2) chickens.push_back(make_pair(j,i));
		}
	}

	vector<pair<int,int>> select;
	
	Select(chickens, homes, select, 0, 0, M);
	
	cout << ans;
	
	return 0;
}
