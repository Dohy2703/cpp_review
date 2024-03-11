#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int T, M, N, K, tmpX, tmpY;
int field[51][51];
int cnt=0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int y, int x){
    field[y][x] = 0;

    for (int i=0; i<4; ++i){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (nx<0 || ny<0 || nx>=M || ny>=N) continue;

        if (field[ny][nx]==1) dfs(ny, nx);
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

        memset(field, 0, sizeof(field));

        for(int j=0; j<K; ++j){
            cin>>tmpX>>tmpY;
            field[tmpY][tmpX] = 1;
        }

        for (int j=0; j<N; ++j){
            for (int k=0; k<M; ++k){
                if (field[j][k]==1){
                    cnt++;
                    dfs(j, k);
                }
            }
        }

        cout<<cnt<<"\n";
    }

    return 0;
}