// https://programmers.co.kr/learn/courses/30/lessons/42890
// 프로그래머스의 다른 분 코드 가져온 것 (직접 푼거 x 저장용임)

#include <bits/stdc++.h>

using namespace std;

// 최소성 확인 
bool possi(vector<int> &vec,int now){
    for(int i=0;i<vec.size();i++)
        if((vec[i]&now)==vec[i])return false;
    return true;
}
int solution(vector<vector<string>> relation) {
    int n=relation.size();
    int m=relation[0].size();
    
    vector<int> ans;
    
    for(int i=1;i<(1<<m);i++){
        set<string> s;  // 중복 제거용 (insert해도 알아서 중복이 제거됨) 
        
        for(int j=0;j<n;j++){
            string now="";
            for(int k=0;k<m;k++){
                if(i&(1<<k)){
                	now+=relation[j][k];
				}
            }
            s.insert(now);
        }
        if(s.size()==n&&possi(ans,i))ans.push_back(i);
    }
    return ans.size();
}
