# Vestigium 

#include <stdio.h>
#include <stdlib.h>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>

using namespace std; // since cin and cout are both in namespace std, this saves some text
    
void init(int *row, int size){
	for(int i = 0; i < size; i++){
		row[i] = -1;
	}
}

int checkCol(vector<int> input, int n){
	int c_cnt = 0;
	bool flag = false;
	// get matrix data
	int *row = (int*)malloc(sizeof(int)*n);
	for(int a = 0; a < n; a++){
	   	init(row, n);
	   	for(int b = 0; b < n; b++){
	   		int m = input[a+b*n];
	   		// if row is alreay 1, the number is already inserted
	   		if(row[m-1] == -1){
	   			row[m-1] = 1;
			}
			else if(flag){
				continue;
			}
			else{
				c_cnt++;
				flag = true;
			}
		}
		flag = false;
	}
	return c_cnt;
}

int main() {
    int t, n, m;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 0; i < t; i++) {
	    cin >> n; // read n.
	    vector<int> arr;  // save all numbers of matrix  
	    int trace = 0, r_cnt = 0, c_cnt = 0; // save number of repeated row/col
	    bool flag = false;

	    // get matrix data and check row
	    int *row = (int*)malloc(sizeof(int)*n);
	    for(int a = 0; a < n; a++){
	    	init(row, n);
	    	for(int b = 0; b < n; b++){
	    		cin >> m;
	    		arr.push_back(m);
	    		// if row is alreay 1, the number is already inserted
	    		if(row[m-1] == -1){
	    			row[m-1] = 1;
				}
				else if(flag){
					continue;
				}
				else{
					r_cnt++;
					flag = true;
				}
			}
			flag = false;
		}
		
		// check col
		c_cnt = checkCol(arr, n);
		
		// calc trace
		for(int a = 0; a < n; a++) trace += arr[a*n+a];
		
		// print result and clear memory
	    cout << "Case #" << i+1 << ": " << trace << " " << r_cnt << " " << c_cnt << endl;
	    arr.clear();
	}
    return 0;
}
