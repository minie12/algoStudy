// https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    bool flag = false;
    
    for(int i = 0; i < prices.size(); i++){
        int current_price = prices[i];
        int cnt = 1;
        flag = false;
        for(int j = i+1; j < prices.size(); j++){
            if(current_price > prices[j]){
                answer.push_back(cnt);
                flag = true;
                break;
            }
            cnt++;
        }
        if(!flag) answer.push_back(cnt-1);
    }
    
    return answer;
}
