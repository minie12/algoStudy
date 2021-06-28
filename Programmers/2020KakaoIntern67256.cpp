// https://programmers.co.kr/learn/courses/30/lessons/67256

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int, pair<int,int>> location;
    
    location[0] = make_pair(1,3);
    location[7] = make_pair(0,2); location[8] = make_pair(1,2); location[9] = make_pair(2,2);
    location[4] = make_pair(0,1); location[5] = make_pair(1,1); location[6] = make_pair(2,1);
    location[1] = make_pair(0,0); location[2] = make_pair(1,0); location[3] = make_pair(2,0);
    
    pair<int,int> lh = make_pair(0,3);
    pair<int,int> rh = make_pair(2,3);
    
    for(int numb : numbers){
        if(numb == 7 || numb == 4 || numb == 1){
            answer += 'L';
            lh = location[numb];
        }
        else if(numb == 9 || numb == 6 || numb == 3){
            answer += 'R';
            rh = location[numb];
        }
        else{
            pair<int,int> loc = location[numb];
            int l_dist = abs(lh.first-loc.first)+abs(lh.second-loc.second);
            int r_dist = abs(rh.first-loc.first)+abs(rh.second-loc.second);
            
            if(l_dist > r_dist){
                answer += 'R';
                rh = loc;
            }
            else if(l_dist < r_dist){
                answer += 'L';
                lh = loc;
            }
            else{
                if(hand == "right"){
                    answer += 'R';
                    rh = loc;
                }
                else{
                    answer += 'L';
                    lh = loc;
                }
            }
        }
    }
    
    return answer;
}
