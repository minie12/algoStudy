//https://programmers.co.kr/learn/courses/30/lessons/12906 

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int val : arr){
        if(answer.empty()) answer.push_back(val);
        else{
            if(answer.back() != val) answer.push_back(val);
        }
    }

    return answer;
}
