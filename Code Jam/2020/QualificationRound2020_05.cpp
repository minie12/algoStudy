#include <stdio.h>
#include <stdlib.h>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>

using namespace std; // since cin and cout are both in namespace std, this saves some text

bool CheckCases(int n, int trace);
void FindDiagonal(int n, int trace, vector<int>& diag);


int main() {
    int t, n, k;
    
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 0; i < t; i++) {
    	cin >> n >> k;
    	
    	if(CheckCases(n, k)) { // check 2 cases which cannot make Latin Square
    		cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
    		continue;
		}

		// find diagonal numbers that fit into trace
		vector<int> diag(n, 0);
		FindDiagonal(n, k, diag);
		
		// bipartite
    	
		// print result and clear memory
	    cout << "Case #" << i+1 << ": " << n << " "<< k << endl;
	}
    return 0;
}

bool CheckCases(int n, int trace){
	if(trace == n+1) return true;
	else if(trace == n*n-1) return true;
	
	return false;
}

void FindDiagonal(int n, int trace, vector<int>& diag){
	int A = n/2;
	int B, C;
	while(A > 0 && A < n+1){
		int remainder = trace - A*(n-2);
		
		// if remainder is 1, it cannot be divided into two number
		// thus subtract A by 1 so that remainder would be bigger than 1
		if(remainder < 2){
			A--;
			continue;
		}
		else if(remainder > n*2){
			A++;
			continue;
		}
		
		B = remainder / 2;
		C = remainder - B;   // B < C
	
		if(A == B && A != C){
			if(C == n){
				A++;
				continue;
			}
			
			B--;
			C++;
		}
		else if(A == C && A != B){
			if(B == 1){
				A--;
				continue;
			}
			else if(C == n){
				A++;
				continue;
			}
			
			B--;
			C++;
		}
		
		break;
	}
	
	for(int i = 0; i < n-2; i ++){
		diag[i] = A;
	}
	diag[n-2] = B;
	diag[n-1] = C;
}

