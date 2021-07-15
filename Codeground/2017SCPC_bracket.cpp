// 부분점수밖에 못얻음...

#include <iostream>
#include <stack>

using namespace std;

int Answer;

bool checkSame(char front, char back){
    if(front == '(' && back == ')') return true;
    else if(front == '[' && back == ']') return true;
    else if(front == '{' && back == '}') return true;
    
    return false;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);  
	int T, test_case;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		stack<int> pt;
		
		string input;
		cin >> input;
		
		int cnt = 0;
		int start_idx = -1;
		int end_idx = -1;
		
		for(int i = 0; i < input.length(); i++){
			char ch = input[i];
		    if(ch == '(' || ch == '{' || ch == '[') pt.push(i);

		    else{
		        if(pt.empty()){
		            Answer = max(Answer, cnt);
		            cnt = 0;
		        }
		        else{
		            int pt_front = pt.top();
    		        pt.pop();
    		        if(checkSame(input[pt_front], ch)) {
    		        	if(cnt == 0) start_idx = pt_front;
    		        	else if(start_idx > pt_front) start_idx = pt_front;
						cnt+=2;
						end_idx = i;
    		        }
    		        else{
    		            Answer = max(Answer, cnt);
    		            cnt = 0;
    		            while(!pt.empty()) pt.pop();
    		        }
		        }
		    }
		}
		
		if(start_idx != -1){
			while(!pt.empty()){
				int left = pt.top();
				pt.pop();
				
				if(start_idx < left && left < end_idx){
					Answer = max(Answer, end_idx - left);
					end_idx = left -1;
				}
				else if(start_idx > left){
					Answer = max(Answer, end_idx - start_idx +1);
					break;
				}
			}	
			
			if(pt.empty()) Answer = max(Answer, end_idx - start_idx +1);
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
