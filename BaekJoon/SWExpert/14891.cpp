#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<string> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int k;
    cin >> k;

    while(k--){
        int no, dir;
        cin >> no >> dir;
        no -= 1;

        vector<int> d(n);
        d[no] = dir;
        
        for(int i = no - 1; i >= 0; i--){
            if(a[i][2] != a[i+1][6]){
                d[i] = -d[i+1];
            }else{
                break;
            }
        }

        for(int i = no + 1; i < n; i++){
            if(a[i-1][2] != a[i][6]){
                d[i] = -d[i-1];
            }else{
                break;
            }
        }

        for(int i = 0; i < n; i++){
            if(d[i] == 0)   continue;
            if(d[i] == 1){
                char temp = a[i][7];
                for(int j = 7; j >= 1; j--){
                    a[i][j] = a[i][j-1];
                }
                a[i][0] = temp;
            }else if(d[i] == -1){
                char temp = a[i][0];
                for(int j = 0; j < 7; j++){
                    a[i][j] = a[i][j+1];
                }
                a[i][7] = temp;
            }
        }
    }

    int ans = 0;
    int sum = 1;
    for(int i = 0; i < n; i++){
        if(a[i][0] == '1'){
            ans += sum;
        }
        sum *= 2;
    }
    cout << ans << '\n';
    return 0;
}

/*

// 8시 20분 -> 9시 10분
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int T[5][9];
int K;

int d[5];

int main(){
    for(int i = 1; i <= 4; i++){
       string str = "";
       cin >> str;
        for(int j = 1; j <= 8; j++){
            T[i][j] = str[j-1]-'0';
        }
    }
    
    cin >> K;

    while(K--){
        for(int i = 1; i <= 4; i++){
            d[i] = 0;
        }
        int no, dir;
        cin >> no >> dir;
        d[no] = dir;

        // 왼쪽
        int temp_d = dir;
        for(int i = no - 1; i >= 1; i--){
            if(T[i][3] != T[i+1][7]){
                temp_d *= -1;
                d[i] = temp_d;
            }else{
                break;
            }
        }

        // 오른쪽
        temp_d = dir;
        for(int i = no + 1; i <= 4; i++){
            if(T[i-1][3] != T[i][7]){
                temp_d *= -1;
                d[i] = temp_d;
            }else{
                break;
            }
        }

        for(int i = 1; i <= 4; i++){
            if(d[i] == 1){
                int temp = T[i][1];
                T[i][1] = T[i][8];
                T[i][8] = T[i][7];
                T[i][7] = T[i][6];
                T[i][6] = T[i][5];
                T[i][5] = T[i][4];
                T[i][4] = T[i][3];
                T[i][3] = T[i][2];
                T[i][2] = temp;

            }else if(d[i] == -1){
                int temp = T[i][1];
                T[i][1] = T[i][2];
                T[i][2] = T[i][3];
                T[i][3] = T[i][4];
                T[i][4] = T[i][5];
                T[i][5] = T[i][6];
                T[i][6] = T[i][7];
                T[i][7] = T[i][8];
                T[i][8] = temp;
            }
        }
    }

    

    int answer = 0;
    int mul[5] = {0, 1, 2, 4, 8 };
    for(int i = 1; i <= 4; i++){
        if(T[i][1] == 1){
            answer += mul[i];
        }   
    }
    cout << answer << endl;
    return 0;
}*/
