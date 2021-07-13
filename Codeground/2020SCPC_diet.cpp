#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 200000

using namespace std;

int Answer;

int main(int argc, char** argv)
{
  // ios_base::sync_with_stdio(0);  // 얘를 넣으면 수행시간이 빨라지는데 왜인지 모르겠음
	int T, test_case;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int menu, days;
		cin >> menu >> days;
		
		int A[MAX], B[MAX];
		
		for(int i = 0; i < menu; i++){
		    cin >> A[i];
		}
		for(int i = 0; i < menu; i++){
		    cin >> B[i];
		}
		
		sort(A, A+menu);
		sort(B, B+menu);

    for(int i = 0 ; i < days; i++){
        Answer =  max(Answer, A[i]+B[days-i-1]);
    }
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
