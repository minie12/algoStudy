//https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool checkPrime(int numb){
    if(numb == 1 || numb == 0) return false;
    
    for(int i = 2; i < numb/2 + 1; i++){
        if(numb%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {    
    set<int> prime;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 1 ; i < numbers.length() +1; i++){
            int numb = stoi(numbers.substr(0, i));
            if(checkPrime(numb)) prime.insert(numb);
        }   
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return prime.size();
}
