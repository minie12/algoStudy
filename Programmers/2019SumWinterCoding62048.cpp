//https://programmers.co.kr/learn/courses/30/lessons/62048

#include <math.h>

using namespace std;

int GCD(int w, int h){
    int c;
	while (h != 0)
	{
		c = w % h;
		w = h;
		h = c;
	}
	return w;
}

long long solution(int w,int h) {
    long long answer = long(w)*h;
    
    int gcd = GCD(w,h);
    int W = w/gcd;
    int H = h/gcd;
    
    double tan = double(H)/W;
    
    long long cut = 0;
    double prev_h = H;
    for(int i = 1; i < W; i++){
        double now_h = tan*(W-i);
        cut += ceil(prev_h) - ceil(now_h) +1;
        prev_h = now_h;
    }
    cut += ceil(prev_h);
    
    answer -= cut*gcd;
    // answer = ((long)w * h) - ((long)w + h - gcd); << 다른사람 풀이 ㅋㅋㅋ 완전 신기함
    
    return answer;
}
