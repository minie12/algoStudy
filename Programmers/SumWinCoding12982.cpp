// https://programmers.co.kr/learn/courses/30/lessons/12982

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    int tot = 0;
    while(answer < d.size() && tot+d[answer] <= budget){
        tot += d[answer];
        answer++;
    }
    
    return answer;
}
