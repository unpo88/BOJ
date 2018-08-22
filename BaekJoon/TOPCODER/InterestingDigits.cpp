#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    vector<int> answer;

    int base;
    cin >> base;

    for(int i = 2; i < base; i++){
        if(((base-1) % i) == 0)
        answer.push_back(i);
    }

    /*for(int n = 2; n < base; n++){
        bool ok = true;
        for(int k1 = 0; k1 < base; k1++){
            for(int k2 = 0; k2 < base; k2++){
                for(int k3 = 0; k3 < base; k3++){
                    if((k1 + k2*base + k3*base*base) % n == 0 && (k1 + k2 + k3) % n != 0){
                        // n의 배수 숫자로 각 숫자의 합이 n의 배수가 아니면
                        // n을 제외합니다.
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok) answer.push_back(n);
    }
    */
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}