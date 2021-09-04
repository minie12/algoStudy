// https://programmers.co.kr/learn/courses/30/lessons/60059

#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> k(key.size(), vector<int>(key.size()));
    
    for(int j = 0; j < key.size(); j++){
        for(int i = key.size()-1; i > -1; i--){
            k[j][key.size()-i-1] = key[i][j];
        }
    }
    
    key = k;
}

bool correct(int x, int y, vector<vector<int>> &key, vector<vector<int>> lock){
    for(int i = 0; i < key.size(); i++){
        for(int j = 0; j < key.size(); j++){
            lock[i+x][j+y] += key[i][j];
        }
    }
    
    for(int i = key.size()-1; i < lock.size() - (key.size()-1); i++){
        for(int j = key.size()-1; j < lock.size() - (key.size()-1); j++){
            if(lock[i][j] != 1) return false; 
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int size = lock.size()+(key.size()-1)*2;
    vector<vector<int>> newLock(size, vector<int>(size, 0));
    
    for(int i = key.size()-1; i < size - key.size()+1; i++){
        for(int j = key.size()-1; j < size - key.size()+1; j++){
            newLock[i][j] = lock[i-key.size()+1][j-key.size()+1];
        }
    }
    
    for(int repeat = 0; repeat < 4; repeat++){
        for(int x = 0; x < key.size()-1+lock.size(); x++){
            for(int y = 0; y < key.size()-1+lock.size(); y++){
                if(correct(x, y, key, newLock)) return true;
            }
        }
        rotate(key);
    }
    
    return false;
}
