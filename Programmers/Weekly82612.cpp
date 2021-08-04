// https://programmers.co.kr/learn/courses/30/lessons/82612

using namespace std;

long long solution(int price, int money, int count)
{
    double answer = 0;
    
    double tot = 0;
    for(int cnt = 1; cnt <= count; cnt++){
        tot += double(price)*cnt;
    }
    
    answer = tot - money > 0 ? tot-money : answer;

    return answer;
}
