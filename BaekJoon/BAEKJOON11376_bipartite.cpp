#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;
const int MAX = 1000;

int work[MAX], worker[MAX*2];
vector<int> possible[MAX];
bool visited[MAX*2];

bool Bipartite(int a){
	visited[a] = true;
	
	for(int b : possible[a/2]){
		if(work[b] == -1|| (!visited[work[b]] && Bipartite(work[b]))){
			worker[a] = b;
			work[b] = a;
			return true;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		for(int j = 0; j < t; j++){
			int numb;
			cin >> numb;
			possible[i].push_back(numb-1);
		}		
	}

	fill(work, work+m, -1);
	fill(worker, worker+n*2, -1);
	
	int match = 0;
	
	for(int i = 0; i < 2*n; i++){
		if(worker[i] == -1){
			fill(visited, visited+2*n, false);
			if(Bipartite(i)) match++;
		}
	}
	
	cout << match << endl;
	
	return 0;
}
