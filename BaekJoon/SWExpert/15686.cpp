#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

#define MAX_INF 987654321
#define MAX_N 51
#define MAX_M 14

int N, M;
int ans = MAX_INF;

int map[MAX_N][MAX_N];
bool check[MAX_M];

vector<pair<int, int> > house;
vector<pair<int, int> > chiken;

void go(int cur_num, int cur_cnt){
    if(cur_num > chiken.size())    return ;

    if(cur_cnt == M){
        int cmp = 0;
        for(int i = 0; i < house.size(); i++){
            int dist = MAX_INF;
            for(int j = 0; j < chiken.size(); j++){
                if(check[j]){
                    int px = house[i].first;
                    int py = house[i].second;
                    int nx = chiken[j].first;
                    int ny = chiken[j].second;
                    int d = abs(px - nx) + abs(py - ny);
                    dist = min(dist, d);
                }
            }
            cmp += dist;
        }
        ans = min(ans,cmp);
        return ;
    }

    check[cur_num] = true;
    go(cur_num + 1, cur_cnt + 1);
    check[cur_num] = false;
    go(cur_num + 1, cur_cnt);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                house.push_back(make_pair(i, j));
            }else if(map[i][j] == 2){
                chiken.push_back(make_pair(i, j));
            }
        }
    }

    go(0, 0);

    cout << ans << endl;


    return 0;
}