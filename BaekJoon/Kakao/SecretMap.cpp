#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int temp1;
int temp2;

vector<int> arr1;
vector<int> arr2;
vector<char> ans;

int main(){
    scanf("%d", &N);

    if(N < 1 || N > 16){
        return 0;
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &temp1);
        arr1.push_back(temp1);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &temp2);
        arr2.push_back(temp2);
    }

    for(int i = 0; i < N; i++){
        temp1 = arr1[i] | arr2[i];

        while(temp1 != 0){
            temp2 = temp1 % 2;
            temp1 /= 2;

            if(temp2 == 1){
                ans.push_back('#');
            }else{
                ans.push_back(' ');
            }
        }
        /*if(ans.size() < N){
            while(ans.size() < N){
                ans.push_back(' ');
            }
        }*/
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < N; i++){
            printf("%c", ans[i]);
        }

        printf("\n");
        ans.resize(0);
    }

    return 0;
}