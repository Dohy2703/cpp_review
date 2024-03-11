#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
queue<pair<int,int>> q;

int plus_[] = {-1, 1, 0};
int mult[] = {1, 1, 2};
int next_ = 0;
bool flag = false;
bool visited[100001] = {false, };

void bfs(int start){
    q.push(make_pair(start, 1));
    visited[start] = true;
    
    while (!q.empty()){
        int now = q.front().first;
        int now_cnt = q.front().second;
        visited[now] = true;
        q.pop();

        for (int i=0; i<3; ++i){
            next_ = (now + plus_[i])*mult[i];

            if (next_<0 && next_>100000) continue;
            if (visited[next_]) continue;

            if (next_==K){
                flag = true;
                break;
            }

            q.push(make_pair(next_, now_cnt+1));
        }

        if (flag){
            cout<<now_cnt;
            break;
        } 
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;

    if (N==K){
        cout<<0;
        return 0;
    }

    bfs(N);

    return 0;
}