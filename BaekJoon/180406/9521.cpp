#include <iostream>
#include <vector>
using namespace std;

long long N;
long long Ai;
long long B, C;
long long map[1000001];
long long B_cnt = 0;
long long C_cnt = 0;

int main() {
   cin >> N;
   

   for (int i = 0; i < N; i++) {
      cin >> Ai;
      map[i] = Ai;
   }

   cin >> B >> C;


   for (int i = 0; i < N; i++) {
      map[i] = map[i] - B;
      B_cnt += 1;
   }

   for (int i = 0; i < N; i++) {
       if(map[i]>0){
            if(map[i] % C == 0){
            C_cnt += map[i] / C;
         }
         else {
            C_cnt += map[i] / C + 1;
         }
       }
   }

   cout << B_cnt + C_cnt;

   return 0;
}