#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    vector<int> numbers;
    int N;
    cin >> N;

    int number;
    for(int i = 0; i < N; i++){
        cin >> number;
        numbers.push_back(number);
    }

    long long answer = 0;

    for(int i = 0; i < numbers.size(); i++){
        long long mul = 1;
        for(int j = 0; j < numbers.size(); j++){
            if(i == j){
               mul *= (numbers[j] + 1);
            }else{
                mul *= numbers[j];
            }
        }
        answer = max(answer, mul);
    }

    cout << answer;

    /*sort(numbers.begin(), numbers.end());
    
    numbers[0]++;

    long long mul = 1;
    for(int i = 0; i < numbers.size(); i++){
        mul *= numbers[i];
    }

    cout << mul;*/
    
    return 0;
}