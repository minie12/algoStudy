/* https://www.acmicpc.net/problem/14888 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Operator{
	PLUS,
	MINUS,
	MULT,
	DIV
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int nums[11];
	vector<Operator> operators;
	
	cin >> N;
	
	// get numbers
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		nums[i] = x;
	}
	// get operators
	int temp;
	cin >> temp;
	for(int i = 0; i < temp; i++) operators.push_back(PLUS);
	cin >> temp;
	for(int i = 0; i < temp; i++) operators.push_back(MINUS);
	cin >> temp;
	for(int i = 0; i < temp; i++) operators.push_back(MULT);
	cin >> temp;
	for(int i = 0; i < temp; i++) operators.push_back(DIV);
	
	long minAns = 1000000000;
	long maxAns = -1000000000;
	do{ // calc the equation
		long res = nums[0];
		for(int i = 0; i < operators.size(); i++){
			Operator op = operators[i];
			switch(op){
				case PLUS:
					res += nums[i+1];
					break;
				case MINUS:
					res -= nums[i+1];
					break;
				case MULT:
					res *= nums[i+1];
					break;
				case DIV:
					res /= nums[i+1];
					break;
			}
		}

		minAns = min(res, minAns);
		maxAns = max(res, maxAns);
	}while(next_permutation(operators.begin(), operators.end()));
	
	cout << maxAns << endl << minAns << endl;
	
	return 0;
}
