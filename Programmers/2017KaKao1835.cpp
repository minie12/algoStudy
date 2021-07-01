//https://programmers.co.kr/learn/courses/30/lessons/1835
// next_permutation 에 관해서 배움
// vector 돌리는것보다 string 돌리는게 빠름 (find가 빠른건지 next_permutation이 빠른건지는 안해봄)
// 조건을 무엇으로 설정하는냐에 따라 실행시간 달라짐 (이 같은 경우는 조건부를 실패할 경우 바로 다음 permutation 확인하는 경우가 더 빨랏음)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string photo = "ACFJMNRT";
    
    do{
        bool fail = false;
        for(string key : data){
            char first = key[0];
            char second = key[2];
            char condition = key[3];
            int distance = key[4] - '0';
            
            int dist = photo.find(first) - photo.find(second);
            dist = abs(dist) - 1;
            
            switch(condition){
                case '>':
                    if(dist <= distance) fail = true;
                    break;
                case '<':
                    if(dist >= distance) fail = true;
                    break;
                case '=':
                    if(dist != distance) fail = true;
            }
            
            if(fail) break;
        }    
        if(!fail) answer++;
    }while(next_permutation(photo.begin(), photo.end()));
    
    return answer;
}
