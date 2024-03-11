#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[1001][3];
int cnt[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    cin>>arr[0][0]>>arr[0][1]>>arr[0][2];

    for (int i=1; i<N; ++i){
        cin>>cnt[0]>>cnt[1]>>cnt[2];

        arr[i][0] += min(arr[i-1][1], arr[i-1][2]) + cnt[0];
        arr[i][1] += min(arr[i-1][0], arr[i-1][2]) + cnt[1];
        arr[i][2] += min(arr[i-1][0], arr[i-1][0]) + cnt[2];
    }

    cout<<min({arr[N-1][0], arr[N-1][1], arr[N-1][2]});
    // 주의 - min({ })는 algorithm 라이브러리에서 사용 가능

    return 0;
}
