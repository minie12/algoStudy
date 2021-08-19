//https://programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int map_info[51][51];

int solution(int N, vector<vector<int>> road, int K) {
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            map_info[i][j] = 5999999;
        }
    }
    
    
    for(int i = 0; i < road.size(); i++){
        if(map_info[road[i][0]][road[i][1]] > road[i][2]){
            map_info[road[i][0]][road[i][1]] = road[i][2];
            map_info[road[i][1]][road[i][0]] = road[i][2];  
        }
    }
    
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(k==i || i==j || j==k) continue;
                if(map_info[i][j] > map_info[i][k] + map_info[k][j]){
                    map_info[i][j] = map_info[i][k] + map_info[k][j];
                }
            }
        }
    }
    
    int answer = 1;
    for(int i = 2; i <= N; i++){
        if(map_info[1][i] <= K) answer++;
    }
    
    return answer;
}
