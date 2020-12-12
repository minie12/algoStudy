#include <stdio.h>
#include <stdlib.h>
#include <iostream> // includes cin to read from stdin and cout to write to stdout

using namespace std; // since cin and cout are both in namespace std, this saves some text

int main() {
    int t;
    string n, ans;
    
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 0; i < t; i++) {
    	ans="";
    	
	    cin >> n; // read n.
	    int prev=0, current, diff;
	    
	    for(int j = 0; j < n.length(); j++){
	    	current = n[j]-'0';
	    	diff = current - prev;

	    	if(diff < 0){
	    		for(int a = 0; a > diff; a--){
	    			ans.append(1, ')');
				}
				ans.append(1, n[j]);
			}
			else if(diff > 0){
	    		for(int a = 0; a < diff; a++){
	    			ans.append(1, '(');
				}
				ans.append(1, n[j]);
			}
			else{
				ans.append(1, n[j]);
			}
			prev = current;
		}
		
		for(int j = 0; j < current; j++){
			ans.append(1, ')');
		}
		
		// print result and clear memory
	    cout << "Case #" << i+1 << ": " << ans << endl;
	}
    return 0;
}
