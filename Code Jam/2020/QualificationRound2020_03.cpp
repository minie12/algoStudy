// Parenting Partnering Returns

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <string.h>


using namespace std;

struct schedule{
	
	schedule(int Order, int S, int E){
		order = Order;
		s = S;
		e = E;
	}
	
	int s;
	int order;
	int e;
};

void sortStart(vector<schedule> &scheduler, int m, int n);

int main(){
	int t, n, s, e;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		
		// organize data into list sorted by start time ----------------------------------------
		vector<schedule> scheduler;
		// put data intp vector		 
		for(int j = 0; j < n; j++){
			cin >> s >> e;
			schedule temp(j, s, e);
			scheduler.push_back(temp);
		}
		
		sortStart(scheduler, 0, n-1); // sort


		// allocate activities to Cameron and Jamie  --------------------------------------------
		vector<string> ans(n);
		bool imp = false;

		int C_endTime = -1;
		int J_endTime = -1;
		
		for(int j = 0; j < n; j++){
			schedule temp = scheduler[j];
			
			if(C_endTime <= temp.s){  // if C end time does not collapse with next activity
				ans[temp.order] = 'C';
			    C_endTime = temp.e;
			}
			else if(J_endTime <= temp.s){ // if C wasn't available but J is, add this
				ans[temp.order] = 'J';
				J_endTime = temp.e;
			}
			else{ // if none is available, go back to savepoint
				imp = true;
				break;
			}
		}
		
		if(imp) cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
		else{
			cout << "Case #" << i+1 << ": ";
			for(int j = 0; j < n; j++){
				cout<< ans[j];
			}
			cout<< endl;
		}
	}
	
	return 0;
}

void merge(vector<schedule> &vec, int m, int middle, int n){
	vector<schedule> temp;
	int i = m, j = middle+1;
	
	while(i <= middle && j <= n){
		if(vec[i].s < vec[j].s) temp.push_back(vec[i++]);
		else temp.push_back(vec[j++]);
	}
	
	while(i <= middle) temp.push_back(vec[i++]);
	while(j <= n) temp.push_back(vec[j++]);
	
	int x = 0;
	for(int k = m; k <= n; k++){
		vec[k] = temp[x++];
	}
}

void sortStart(vector<schedule> &scheduler, int m, int n){
	if(m < n){
		int middle = (m+n)/2;
		// divide
		sortStart(scheduler, m, middle);
		sortStart(scheduler, middle+1, n);
		
		merge(scheduler, m, middle, n);
	}
}
