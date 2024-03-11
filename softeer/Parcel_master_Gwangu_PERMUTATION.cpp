#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int answer = 2e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    vector<int> rail(n,0);

    for (int i=0; i<n; ++i){
        cin>>rail[i];
    }

    sort(rail.begin(), rail.end());

    do{
        int cnt=0, sum=0, temp=0, idx=0;

        while(cnt<k){ // 일을 k번 함
            temp = 0;  // 현재 바구니 무게

            while (temp + rail[idx] <= m){
                temp += rail[idx];
                sum += rail[idx];
                idx = (idx+1) % n; // 레일 인덱스 증가, 레일은 최대 n개니까 %n
            }
            cnt++;  // 종료한 일의 개수 증가
        }
        answer = min(sum, answer);  // 무게 합이 최소인지 비교
    } while (next_permutation(rail.begin(), rail.end()));

    cout<<answer;
    return 0;
}