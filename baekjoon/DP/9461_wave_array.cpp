#include <iostream>

using namespace std;
int T, N;
long long arr[101] = {0,}; // 자료형 주의!!

long long calc_pn(int M){
    if (M<=3) return arr[M] = 1;
    if (M<=5) return arr[M] = 2;
    if (arr[M]!=0) return arr[M]; // DP의 핵심
    return arr[M] = calc_pn(M-2)+calc_pn(M-3);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=1; i<=5; ++i){
        calc_pn(i);
    }


    cin>>T;
    for (int i=0; i<T; ++i){
        cin>>N;
        cout<<calc_pn(N)<<"\n";
    }
    return 0;
}
