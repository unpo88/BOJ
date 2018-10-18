#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

int map[51][51];
bool check[14];

int answer = 987654321;

void DFS(int idx, int cnt){
    if(idx > chicken.size())    return ;

    if(cnt == M){
        int sum = 0;
        for(int i = 0; i < house.size(); i++){
            int dist = 987654321;
            for(int j = 0; j < chicken.size(); j++){
                if(check[j]){
                    int d = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                    dist = min(dist, d);
                }
            }
            sum += dist;
        }
        answer = min(answer, sum);
        return ;
    }

    check[idx] = true;
    DFS(idx + 1, cnt + 1);
    check[idx] = false;
    DFS(idx + 1, cnt);
}

int main(){
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                chicken.push_back(make_pair(i, j));
            }else if(map[i][j] == 1){
                house.push_back(make_pair(i, j));
            }
        }
    }

    DFS(0, 0);

    cout << answer << '\n';

    return 0;
}