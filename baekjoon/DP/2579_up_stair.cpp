#include <iostream>

using namespace std;
int N;
int stair[301];
int score[301][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for (int i=1; i<=N; ++i){
        cin>>stair[i];
    }

    score[1][0] = stair[1];
    score[2][0] = stair[1]+stair[2];
    score[2][1] = stair[2];
    score[3][1] = stair[1]+stair[3];
    score[4][0] = score[3][1] + stair[4];
    score[4][1] = score[2][0] + stair[4];
     
    for (int i=1; i<=N; ++i){
        score[i][0] = score[i-1][1] + stair[i];
        score[i][1] = max(score[i-2][0], score[i-2][1]) + stair[i];
    }

    // 0 : 점프X, 1 : 점프O

    cout<<max(score[N][0], score[N][1]);

    return 0;
}
