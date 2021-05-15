//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;

    queue<pair<int,int>> on_bridge;  // weight, time

    int index = 0;
    int total_w = 0;
    while(index < truck_weights.size()){
        if(total_w + truck_weights[index] <= weight){
            int w = truck_weights[index];
            on_bridge.push(make_pair(w, time));
            total_w += w;
            index++;
        }

        // check if front truck has passed the brigde
        if(time - on_bridge.front().second + 1 >= bridge_length) {
            pair<int, int> temp = on_bridge.front();
            on_bridge.pop();
            total_w -= temp.first;
        }

        time++;
    }

    if(!on_bridge.empty()){
        time = on_bridge.back().second + bridge_length;
    }

    return time;
}
