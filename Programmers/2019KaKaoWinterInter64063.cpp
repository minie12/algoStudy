// https://programmers.co.kr/learn/courses/30/lessons/64063

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> check;

long long search(long long room){
    if(check[room] == 0) return room;
    
    return check[room] = search(check[room]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i = 0; i < room_number.size(); i++){
        long long wanted = room_number[i];
        
        if(check[wanted] == 0){
            answer.push_back(wanted);
            check[wanted] = wanted+1;
        }
        else{
            wanted = search(wanted);
            answer.push_back(wanted);
            check[wanted] = wanted+1;
        }
    }
    
    return answer;
}
