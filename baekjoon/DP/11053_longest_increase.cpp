#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int dp[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for (int i=0; i<N; ++i){
        cin>>arr[i];
    }

    dp[0] = 1;

    for (int i=1; i<N; ++i){
        dp[i] = 1;
        for (int j=0; j<i; ++j){
            if (arr[j]<arr[i]){
                dp[i] = max(arr[i], arr[j]+1);
            }
        }
    }

    cout << *max_element(dp, dp+N);

    return 0;
}
