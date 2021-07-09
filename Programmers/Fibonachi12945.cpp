//https://programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

int fibo(int a, int b, int cnt){
    int ans = (a % 1234567 + b% 1234567)% 1234567;
    if(cnt == 2) return ans;
        
    return fibo(b, ans, --cnt);
}

int solution(int n) {
    int answer = 0;
    
    answer = fibo(0,1,n);
    return answer;
}
