//https://programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> basket;
    
    int top = -1; // basket top
    
    for(int i = 0; i < moves.size();i++){
        int move = moves[i]-1;
        for(int j = 0; j < board.size(); j++){
            if(board[j][move] != 0){
                int figure = board[j][move];
                if(top == figure){ // if basket has same figure
                    answer++;
                    basket.pop();
                    if(!basket.empty()) top = basket.top();
                    else top = -1;
                }
                else{
                    basket.push(figure);
                    top = figure;
                }
                
                board[j][move] = 0;
                break;
            }
        }
    }
    
    return answer*2;
}
