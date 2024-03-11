#include <iostream>
#include <algorithm>

using namespace std;

int N;
int wine[10001];
int amount[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for (int i=0; i<N; ++i){
        cin>>wine[i];
    }

    amount[0] = wine[0];
    amount[1] = wine[0]+wine[1];
    amount[2] = max({wine[0]+wine[2], wine[1]+wine[2], amount[1]});
    // amount[3] = max({wine[0]+wine[2]+wine[3], wine[0]+wine[1]+wine[3], amount[2]});

    for (int i=3; i<N; ++i){
        amount[i] = max({amount[i-3]+wine[i-1]+wine[i], amount[i-2]+wine[i], amount[i-1]});
    }

    cout<<amount[N-1];
 
    return 0;
}
