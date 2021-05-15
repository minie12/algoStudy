// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> date_numb;
    
    for(int i = 0; i < progresses.size(); i++){
        float left_p = 100 - progresses[i];
        int speed = speeds[i];
        
        date_numb.push_back(ceil(left_p/speed));
    }
    
    int prev_date = date_numb[0];
    int cnt = 1;
    for(int i = 1; i < date_numb.size(); i++){
        int date = date_numb[i];
        
        if(prev_date < date){
            answer.push_back(cnt);
            cnt = 1;
            prev_date = date;
        }
        else cnt++;
    }
    answer.push_back(cnt);
    
    return answer;
}
