// https://programmers.co.kr/learn/courses/30/lessons/12905

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[0].size(); j++){
            if(board[i][j] == 1){
                board[i][j] = min(board[i-1][j-1],min(board[i-1][j],board[i][j-1])) + 1;
                answer = max(board[i][j], answer);
            }
        }
    }

    return answer*answer;
}
