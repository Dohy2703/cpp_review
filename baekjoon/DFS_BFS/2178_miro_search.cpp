#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
string miro[101];
bool visited[101][101];
int real_miro[101][101];
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int y, int x){ 
    q.push(make_pair(y, x));
    visited[y][x] = true;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i=0; i<4; ++i){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx<0 || ny<0 || nx>=M || ny>=N) continue;
            if (visited[ny][nx]==true) continue;
            if (real_miro[ny][nx]==0) continue;

            real_miro[ny][nx] = real_miro[curY][curX]+1;
            q.push(make_pair(ny, nx));
            visited[ny][nx] = true;
        }    
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;

    for (int i=0; i<N; ++i){
        cin>>miro[i];
    }

    for (int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            real_miro[i][j] = miro[i][j] - '0';
        }
    }

    bfs(0, 0);

    // for (int i=0; i<N; ++i){
    //     for (int j=0; j<M; ++j){
    //         cout<<real_miro[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<real_miro[N-1][M-1];

    return 0;
}