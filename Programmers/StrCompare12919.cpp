// https://programmers.co.kr/learn/courses/30/lessons/12919

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    int loc = -1;
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i].compare("Kim") == 0){
            loc = i;
            break;
        }
    }
    
    answer.append(to_string(loc));
    answer.append("에 있다");
    
    return answer;
}
