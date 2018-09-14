#include <iostream>
#include <string>
using namespace std;

string dart;
int nArr[3];
int cnt;
int idx;

int main(){
    cin >> dart;

    for(int i = 0; i < dart.size(); i++){
        if(cnt == 0){
            int n = dart[i] - 48;
            nArr[idx] = n;
        }else if(cnt == 1){
            if(dart[i] == '0'){
                nArr[idx] *= 10;
                cnt --;
            }else if(dart[i] == 'S'){
                int n = nArr[idx];
                nArr[idx] = n;
            }else if(dart[i] == 'D'){
                int n = nArr[idx];
                nArr[idx] = n * n;
            }else if(dart[i] == 'T'){
                int n = nArr[idx];
                nArr[idx] = n * n * n;
            }
        }else{
            if(dart[i] == '*'){
                nArr[idx] *= 2;
                if(idx - 1 >= 0){
                    nArr[idx - 1] *= 2;
                }
            }else if(dart[i] == '#'){
                nArr[idx] *= -1;
            }else{
                i --;
            }
            idx++;
        }

        cnt ++;
        cnt = cnt % 3;
    }

    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += nArr[i];
    }

    cout << sum << endl;

    return 0;
}