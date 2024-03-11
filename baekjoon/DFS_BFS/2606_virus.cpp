#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[101];
int visited[101] = {0};
int cnt = 0;

void dfs(int start){
    visited[start] = 1;

    for (int i=0; i<graph[start].size(); ++i){
        if (visited[graph[start][i]]==0){
            dfs(graph[start][i]);  
            cnt++;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, P, u, v;  // number, pair
    cin>>N>>P;

    for (int i=0; i<P; ++i){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout<<cnt;

    return 0;
}