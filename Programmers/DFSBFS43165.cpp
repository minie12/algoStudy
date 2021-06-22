//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int answer = 0;

int add_sub(vector<int> numbers, int target, int index, int sum){
    if(index == numbers.size()){
        if(sum == target) answer ++;
        return 0;
    }
    
    add_sub(numbers, target, index+1, sum+numbers[index]);
    add_sub(numbers, target, index+1, sum-numbers[index]);
    
    return 0;
}

int solution(vector<int> numbers, int target) {
    add_sub(numbers, target, 0, 0);
    
    return answer;
}
