#include <cstdio>
#include <algorithm>
using namespace std;

int numRed, numBlue;

int onlyRed, onlyBlue, bothColors;

int answer = -100000;

int N;

int main(){
    scanf("%d %d %d %d %d", &numRed, &numBlue, &onlyRed, &onlyBlue, &bothColors);

    N = numRed + numBlue;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if((numRed - j) >= 0 && (numBlue - j) >= 0){
                answer = max(answer, (numRed - j) * onlyRed + (numBlue - j) * onlyBlue + (j * 2) * bothColors);
            }
        }
    }

    printf("%d", answer);
    return 0;
}