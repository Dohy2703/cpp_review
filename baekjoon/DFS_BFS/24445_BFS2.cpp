#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int cnt = 0;

void bfs(int start){
    int element;
    queue<int> q;
    q.push(start);
    visited[start] = ++cnt;

    while (!q.empty()){
        element = q.front();
        q.pop();

        for (int i=0; i<graph[element].size(); ++i){
            if (visited[graph[element][i]]==0){
                visited[graph[element][i]] = ++cnt;
                q.push(graph[element][i]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R, u, v;
    cin>>N>>M>>R;

    for (int i=0; i<M; ++i){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=N; ++i){
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    bfs(R);

    for (int i=1; i<=N; ++i){
        cout<<visited[i]<<"\n";
    }


    return 0;
}