#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int num;

vector<int> plus;
vector<int> minus;

int one;
int zero;

int answer;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);

        if(num == 1){
            one++;
        }else if(num > 0){
            plus.push_back(num);
        }else if(num < 0){
            minus.push_back(num);
        }else{
            zero++;
        }
    }

    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    if(plus.size() % 2 == 1){
        plus.push_back(1);
    }

    if(minus.size() % 2 == 1){
        minus.push_back(zero > 0 ? 0 : 1);
    }

    answer = one;

    for(int i = 0; i < plus.size(); i += 2){
        answer += plus[i] * plus[i + 1];
    }

    for(int i = 0; i < minus.size(); i += 2){
        answer += minus[i] * minus[i + 1];
    }

    printf("%d\n", answer);
    return 0;
}