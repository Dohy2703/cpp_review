#include <iostream>
#include <queue>

using namespace std;
int R, C, goalY, goalX;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

string Map[50];
char MAP[50][50];
bool visitedR[50][50];  // Rain
bool visitedP[50][50];  // Person
queue<pair<int, int>> qR, qP;

int main(){
    cin>>R>>C;
    for (int i=0; i<R; ++i){
        cin>>Map[i];
    }

    for (int i=0; i<R; ++i){
        for (int j=0; j<C; ++j){
            MAP[i][j] = Map[i][j];
            if (MAP[i][j]=='W'){
                visitedP[i][j]=1;
                qP.push(make_pair(i, j));
            }
            else if (MAP[i][j]=='H') goalY=i, goalX=j;
            else if (MAP[i][j]=='*'){
                visitedR[i][j]=1;
                qR.push(make_pair(i,j));
            }
        }
    }

    int answer = 0;

    while(!qP.empty()){
        int sz = qR.size();
        while(sz--){
            auto [cy, cx] = qR.front();
            qR.pop();
            for (int i=0; i<4; ++i){
                int ny=cy+dy[i];
                int nx=cx+dx[i];

                if (ny<0 || nx<0 || ny>=R || nx>=C) continue;
                if (MAP[ny][nx]=='X' || MAP[ny][nx]=='H') continue;
                if (visitedR[ny][nx]) continue;

                visitedR[ny][nx] = 1;
                qR.push(make_pair(ny, nx));
            }
        }
        sz = qP.size();
        while(sz--){
            auto [cy, cx] = qP.front();
            qP.pop();

            if (cy==goalY && cx==goalX){
                cout<<answer;
                return 0;
            }

            for (int i=0; i<4; ++i){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (ny<0 || nx<0 || ny>=R || nx>=C) continue;
                if (visitedP[ny][nx] || visitedR[ny][nx]) continue;
                if (MAP[ny][nx]=='X') continue;

                visitedP[ny][nx]=1;
                qP.push(make_pair(ny, nx));
            }
        }
        answer++;
    }
    cout<<"FAIL";
}


