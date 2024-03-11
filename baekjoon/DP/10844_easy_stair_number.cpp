#include <iostream>
#include <algorithm>
#define mod 1000000000

using namespace std;

int N;
// 점화식 max(DP[i-1][j], DP[i-1][j-W[i]])
int DP[101][10] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    for (int i=1; i<=9; ++i){
        DP[1][i] = 1;       
    }
    
    for (int i=2; i<=N; ++i){
        for (int j=0; j<10; ++j){
            if (j==0) DP[i][0] = DP[i-1][j+1];
            else if (j==9) DP[i][9] = DP[i-1][j-1];
            else DP[i][j] = DP[i-1][j-1] + DP[i-1][j+1];

            DP[i][j] %= mod;
        }
    }

    int result = 0;
    for (int i=0; i<10; ++i){
        result = (result + DP[N][i]) % mod;
    }

    cout<<result<<"\n";

    return 0;
}