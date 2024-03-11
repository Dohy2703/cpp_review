// #include <iostream>

// using namespace std;
// int N;
// int arr[501];
// int temp[501];

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin>>N;
//     cin>>arr[0];

//     for (int i=1; i<=N; ++i){
//         for (int j=0; j<i; ++j){
//             cin>>temp[j];
//         }
//         for (int j=0; j<i; ++j){
//             arr[j] = temp[j]+max(arr[j], arr[j+1]);
//             cout<<arr[j]<<" ";
//         }
//         cout<<endl;
//     }

//     int answer = -1000000;
//     for (int i=0; i<N; ++i){
//         if (answer < arr[i]) answer = arr[i];
//     }

//     cout<<answer;

//     return 0;
// }
