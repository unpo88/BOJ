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

    return 0;
}