#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
string arr[26];
int visited[26][26];
queue<pair<int,int>> q;
vector<int> result;

int dy[]={-1, 1, 0, 0};
int dx[]={0, 0, -1, 1};

int N, cnt = 0;

void bfs(int x, int y){
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    cnt++;

    while (!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i=0; i<4; ++i){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if (visited[nx][ny]==1) continue;
            if (arr[nx][ny]=='0') continue;

            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
            cnt++;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for (int i=0; i<N; ++i){
        cin>>arr[i];
    }

    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            if (arr[i][j]=='1' && visited[i][j]==0){
                cnt = 0;
                bfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout<<result.size()<<"\n";
    for (int i=0; i<result.size(); ++i){
        cout<<result[i]<<"\n";
    }

    return 0;
}