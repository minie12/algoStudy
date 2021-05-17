//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> su1 = {1, 2, 3, 4, 5};
    vector<int> su2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> su3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int ans1 = 0, ans2 = 0, ans3 = 0;
    int su1_size = 5, su2_size = 8, su3_size = 10;
    
    for(int i = 0; i < answers.size(); i++){
        int ans = answers[i];
        if(ans == su1[i%su1_size]) ans1++;
        if(ans == su2[i%su2_size]) ans2++;
        if(ans == su3[i%su3_size]) ans3++;
    }
    
    if(ans1 >= ans2 && ans1 >= ans3) answer.push_back(1);
    if(ans2 >= ans1 && ans2 >= ans3) answer.push_back(2);
    if(ans3 >= ans1 && ans3 >= ans2) answer.push_back(3);
    
    return answer;
}
