// https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool hot = true;  

    // organize scoville in decrement order 
    priority_queue<int, vector<int>, greater<int> > sc;
    for(int i = 0; i < scoville.size(); i++){
        sc.push(scoville[i]);
        // check if all scoville is already above K
        if(scoville[i] < K) hot = false;  
    }

    if(hot) return -1;

    while(sc.top() < K && sc.size() > 1){
        int sc1 = sc.top();
        sc.pop();
        int sc2 = sc.top();
        sc.pop();

        sc.push(sc1 + sc2*2);
        answer++;
    }

    if(sc.top() < K) return -1;

    return answer;
}
