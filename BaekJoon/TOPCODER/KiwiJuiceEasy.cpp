#include <vector>
#include <cstdio>
using namespace std;
int main(){
    int N;
    int Number;

    vector<int> capacities;
    vector<int> bottles;
    vector<int> fromId;
    vector<int> toId;
    
    // capacities 입력
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &Number);
        capacities.push_back(Number);
    }

    // bottles 입력
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &Number);
        bottles.push_back(Number);
    }

    // fromId 입력
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &Number);
        fromId.push_back(Number);
    }

    // toId 입력
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &Number);
        toId.push_back(Number);
    }

    for(int i = 0; i < fromId.size(); i++){
        int space = capacities[toId[i]] - bottles[toId[i]];         // 언제나 총합은 똑같다
        int move = min(bottles[fromId[i]], space);                  // 가장 작은 값이 움직이는 값이 된다
        bottles[fromId[i]] -= move;                                 // 빼준다
        bottles[toId[i]] += move;                                   // 더해준다
    }

    for(int i = 0; i < bottles.size(); i++){
        printf("%d ", bottles[i]);
    }
    
    return 0;
}