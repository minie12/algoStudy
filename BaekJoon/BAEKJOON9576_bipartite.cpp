#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int A[MAX], B[MAX];
vector<int> possible[MAX];
bool visited[MAX];

bool Bipartite(int a){
	visited[a] = true;
	
	int i = possible[a][0];
	int j = possible[a][1];
	
	cout << i << "  " << j << endl;
	
	for(int x = i; x <= j; x++){
		if(B[x] == -1 || (!visited[B[x]] && Bipartite(B[x]))){
			A[a] = x;
			B[x] = a;
			return true;
		}
	}
	
	return false;
}

int main(){
	int t, n, m;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		
		fill(A, A+m, -1);
		fill(B, B+n, -1);
		
		int a, b;
		for(int j = 0; j < m; j++){
			cin >> a >> b;
			// possible numbers are between a ~ b
			possible[j].push_back(a-1);
			possible[j].push_back(b-1);
		}
		
		int match = 0;
		
		for(int j = 0; j < m; j++){
			if(A[j] == -1){
				fill(visited, visited+MAX, false);
				if(Bipartite(j)) match++;
			}	
		}
		
		cout << match << endl;
	}
	return 0;
}


