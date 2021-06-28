//https://programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> dart;
    string point = "";
    for(char key : dartResult){
        if(isdigit(key)) point += key;
        else{
            int numb = (point == "") ? 0 : stoi(point);
            int prev_numb = 0;
            switch(key){
                case 'S':
                    point = "";
                    break;
                case 'D':
                    numb = numb*numb;
                    point = "";
                    break;
                case 'T':
                    numb = numb*numb*numb;
                    point = "";
                    break;
                case '*':
                    numb = dart.back();
                    dart.pop_back();
                    prev_numb = dart.back();
                    dart.pop_back();
                    dart.push_back(prev_numb*2);
                    numb *= 2;
                    break;
                case '#':
                    numb = dart.back();
                    dart.pop_back();
                    numb *= -1;
                    break;
            }
            dart.push_back(numb);
        }
    }
    
    for(int num : dart) answer += num;
    
    return answer;
}
