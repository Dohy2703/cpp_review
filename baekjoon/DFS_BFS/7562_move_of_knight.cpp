#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int T, I, now_y, now_x, target_y, target_x;
int dx[]={-2, -2, -1, -1, 1, 1, 2, 2};
int dy[]={1, -1, 2, -2, 2, -2, 1, -1};
queue<pair<int, int>> q;
int chess[301][301];
bool visited[301][301];

void bfs(int x, int y){
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;

        if (curX == target_x && curY == target_y) break;

        q.pop();

        for (int i=0; i<8; ++i){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx<0 || ny<0 || nx>=I || ny>=I) continue;
            if (visited[nx][ny]) continue;

            // cout<<nx<<" "<<ny<<" ";

            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
            chess[nx][ny] = chess[curX][curY]+1;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;

    for (int i=0; i<T; ++i){
        cin>>I>>now_x>>now_y>>target_x>>target_y;

        memset(chess, 0, sizeof(chess));
        memset(visited, 0, sizeof(visited));
        
        queue<pair<int, int>>().swap(q);

        bfs(now_x,now_y);

        cout<<chess[target_x][target_y]<<"\n";
    }

    return 0;
}