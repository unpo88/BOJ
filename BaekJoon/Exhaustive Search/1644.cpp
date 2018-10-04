#include <cstdio>
#include <vector>
using namespace std;

vector<int> v(1, 2);
int N;
bool np[4000000];

int sum;
int l, r;

int result;

void E(){
    for(int i = 3; i < 4000000; i += 2){
        if(np[i])   continue;
        v.push_back(i);
        if(1LL*i*i >= 4000000)  continue;
        for(int j = i * i; j < 4000000; j += i * 2){
            np[j] = true;
        }
    }
}

int main(){
    scanf("%d", &N);
    E();
    while(1){
        if(sum >= N){
            sum -= v[l++];
        }else if(r == v.size()) break;
        else sum += v[r++];
        
        if(sum == N)
            result++;
    }
    printf("%d\n", result);
    return 0;
}