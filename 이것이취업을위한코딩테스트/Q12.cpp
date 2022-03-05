#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool exist(set<vector<int>> &map, int a, int b, int c){
    vector<int> v = {a, b, c};
    if(map.find(v) != map.end()) return true;
    return false;
}

bool Possible(set<vector<int>> &map){
    for(vector<int> frame : map){
        int x = frame[0], y = frame[1], type = frame[2];
        
        if(type == 0){ // column
            if(y == 0) continue;
            if(exist(map, x, y-1, 0) || exist(map, x, y, 1) || exist(map, x-1, y, 1)) continue;
            return false;
        }
        else{
            if(exist(map, x, y-1, 0) || exist(map, x+1, y-1, 0) || exist(map, x-1, y, 1) && exist(map, x+1, y, 1)) continue;
            
             return false;
        }
    }
               
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> map;
    
    for(vector<int> frame : build_frame){
        // {x, y, type, install}
        vector<int> build = {frame[0], frame[1], frame[2]};
        if(frame[3] == 0){ // del
            map.erase(build);
            if(!Possible(map)) map.insert(build);
        }
        else{ // install
            map.insert(build);
            if(!Possible(map)) map.erase(build);
        }
    }
    
    for(vector<int> frame : map){
        answer.push_back(frame);
    }
    return answer;
}
