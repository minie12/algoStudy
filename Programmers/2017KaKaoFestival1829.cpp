// https://programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool checked[100][100];

int searchColor(int m, int n, vector<vector<int>> picture, int x, int y, int type){
    checked[y][x] = true;
    int area = 1;
    
    
    if(x+1 < n && type == picture[y][x+1] && !checked[y][x+1]) area += searchColor(m,n,picture,x+1,y,type);
    if(x-1 >= 0 && type == picture[y][x-1] && !checked[y][x-1]) area += searchColor(m,n,picture,x-1,y,type);
    if(y+1 < m && type == picture[y+1][x] && !checked[y+1][x]) area += searchColor(m,n,picture,x,y+1,type);
    if(y-1 >= 0 && type == picture[y-1][x] && !checked[y-1][x]) area += searchColor(m,n,picture,x,y-1,type);
    
    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // init checked
    memset(checked,0,sizeof(checked));  // << 이게 필수임 ㅋㅋㅋㅋ ㅜㅠ 
    
    for(int i = 0; i < m; i++){
        for(int j =0; j < n; j++){
            int area = 0;
            if(!checked[i][j] && picture[i][j] != 0){
                number_of_area++;
                area = searchColor(m,n,picture,j,i,picture[i][j]);
                // area = countArea(m,n,picture,i,j,picture[i][j]);
            }
            
            if(area > max_size_of_one_area) max_size_of_one_area = area;
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
