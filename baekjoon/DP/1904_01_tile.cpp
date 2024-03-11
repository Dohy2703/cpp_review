#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int N;
int arr[1000001];

int cases(int n){
    if (n==1) return arr[1] = 1;
    if (n==2) return arr[2] = 2;
    if (arr[n]!=0) return arr[n];
    return arr[n] = (cases(n-1) + cases(n-2)) % 15746;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    clock_t start, finish;
    start = clock();

    cout<<cases(N)<<"\n";

    finish = clock();
    cout<<finish - start;

    return 0;
}

