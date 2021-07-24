// https://programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int solution(vector<vector<int> > maps)
{     
    int route[101][101];
    
    // init array
    for(int i =0; i < 101; i++){
        for(int j = 0; j < 101; j++) route[i][j] = 10001;
    }
    route[0][0] = 1;
    
    
    int x_n[] = {1,0,-1,0};
    int y_n[] = {0,1,0,-1};
    
    queue<pair<int,int>> paths;
    paths.push(make_pair(0,0));
    
    int m = maps.size(); int n = maps[0].size();
    
    while(!paths.empty()){
        pair<int, int> coor = paths.front();
        paths.pop();
            
        for(int i = 0; i < 4; i++){
            int x = coor.first + x_n[i];
            int y = coor.second + y_n[i];
            
            if(n <= x || m <= y || 0 > x || 0 > y) continue;
            if(maps[y][x] == 0) continue;
            if(route[y][x] > route[coor.second][coor.first]+1){
                route[y][x] = route[coor.second][coor.first]+1;
                paths.push(make_pair(x,y));
            }
        }  
    }
    
    if(route[m-1][n-1] == 10001) return -1;
    return route[m-1][n-1];
}
