//https://programmers.co.kr/learn/courses/30/lessons/12980

using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n > 1){
        if(n % 2 == 0) n = n/2;
        else{
            ans++;
            n--;
        }
    }
    
    if(n <= 1) ans++;

    return ans;
}
