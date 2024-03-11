#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, M, N, K, tmpX, tmpY;
int field[51][51];
bool visited[51][51];  // 나중에 초기화가 필요할 듯
int cnt=0;
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int y, int x){
    q.push(make_pair(y,x));
    visited[y][x] = 1;
    // cnt++;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i=0; i<4; ++i){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx<0 || ny<0 || nx>=M || ny>=N) continue;
            if (visited[ny][nx]) continue;
            if (field[ny][nx]==0) continue;

            visited[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;

    for (int i=0; i<T; ++i){
        cnt = 0;
        cin>>M>>N>>K;

        for (int j=0; j<N; ++j){
            for (int k=0; k<M; ++k){
                field[j][k] = 0;
                visited[j][k] = false;
            }
        }


        for(int j=0; j<K; ++j){
            cin>>tmpX>>tmpY;
            field[tmpY][tmpX] = 1;
        }

        for (int j=0; j<N; ++j){
            for (int k=0; k<M; ++k){
                if (visited[j][k]==false && field[j][k]==1){
                    cnt++;
                    bfs(j, k);
                }
            }
        }

        cout<<cnt<<"\n";
    }

    return 0;
}