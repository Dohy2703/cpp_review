#include <iostream>
#define DIV 1000000000

using namespace std;
int X;
int arr[101][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>X;

    for (int i=1; i<10; ++i){
        arr[0][i] = 1;
    }

    for (int i=1; i<X; ++i){
        for (int j=0; j<10; ++j){
            if (j==0){
                arr[i][j]+=arr[i-1][j+1] % DIV;
            }
            else if (j==9){
                arr[i][j]+=arr[i-1][j-1] % DIV;
            }
            else{
                arr[i][j]+=(arr[i-1][j-1]+arr[i-1][j+1]) % DIV;
            }
        }
    }

    int answer = 0;

    for (int i=0; i<10; ++i){
        answer = (answer+arr[X-1][i])%DIV; // 이 부분이 중요
    }

    // for (int i=0; i<10; ++i){
    //     cout<<arr[X-1][i]<<" ";
    //     cout<<"\n";
    // }

    cout<<answer;

    return 0;
}


/*

  1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
        ...
        (100)

=>

  1 1 1 1 1 1 1 1 1
1 1 2 2 2 2 2 2 2 1
1 2 3 4 4 4 4 4 3 2
        ...


*/