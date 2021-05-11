// https://programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), desc);
    
    int index = citations.size() / 2;
    while(index < citations.size()){
        if(citations[index] >= (index+1)) {
            if(index == citations.size() - 1) return index + 1;
            index++;
        }
        else{
            if(citations[index-1] >= index ) return index;
            else break;
        }
    }
    
    index = citations.size() / 2 - 1;
    while(index >= 0){
        if(citations[index] < index) index--;
        else{
            return index;
        }
    }
    
    return 0;
}
