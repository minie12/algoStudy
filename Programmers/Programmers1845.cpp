// https://programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int choose_num = nums.size()/2;
    unordered_map<int,int> pokemon;
    
    for(int num : nums){
        pokemon[num] = 1;
    }
    
    if(pokemon.size() >= choose_num) return choose_num;
    
    return pokemon.size();
}
