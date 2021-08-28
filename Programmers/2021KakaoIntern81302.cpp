//https://programmers.co.kr/learn/courses/30/lessons/81302

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkP(vector<string> seats, int i, int j){
    if(i+2 < 5){ // down
        if(seats[i+2][j]=='P' && seats[i+1][j]!='X') return false;
    }
    if(j+2 < 5){ // right
        if(seats[i][j+2]=='P' && seats[i][j+1]!='X') return false;
    }
    
    if(i+1 < 5 && j+1 < 5){  
        // side by side
        if(seats[i][j+1] =='P' || seats[i+1][j]=='P') return false;

        
        // down diagonal right
        if(seats[i+1][j+1] == 'P'){
            if(seats[i][j+1]!='X' || seats[i+1][j]!='X') return false;
        }
        // down diagonal left
        if(j>0){
            if(seats[i+1][j-1]=='P'){
                if(seats[i+1][j]!='X' || seats[i][j-1]!='X') return false;
            }
        }
    }
    else if(j+1 < 5){
        if(seats[i][j+1] =='P') return false;
    }
    else if(i+1 < 5){
        if(seats[i+1][j] == 'P') return false;
        // down diagonal left
        if(j>0){
            if(seats[i+1][j-1]=='P'){
                if(seats[i+1][j]!='X' || seats[i][j-1]!='X') return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++){
        bool far = true;
        
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(places[i][j][k] == 'P'){
                    if(!checkP(places[i], j, k)){
                        answer.push_back(0);
                        far = false;
                        break;
                    }
                }
            }
            if(!far) break;
        }
        if(far) answer.push_back(1);
    }
    
    return answer;
}
