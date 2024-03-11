#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int visited[100001];
vector<int> graph[100001];
int cnt = 0;
int result[100001];

void dfs(int start){
    if (visited[start]==1) return;

    visited[start] = 1;
    cnt++;
    result[start] = cnt;
    
    for (int i=0; i<graph[start].size(); ++i){
        dfs(graph[start][i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R, u, v;
    cin>>N>>M>>R;

    for (int i=1; i<=M; ++i){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=N; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);

    for (int i=1; i<=N; ++i){
        cout<<result[i]<<"\n";
    }    

    return 0;
}
