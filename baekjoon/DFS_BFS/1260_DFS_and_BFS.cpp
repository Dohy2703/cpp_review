#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[10001];
queue<int> q;
int visitedD[1001];
int visitedB[1001];
int resultD[1001];
int resultB[1001];
int cntD=0;
int cntB=0;

void dfs(int start){
    visitedD[start] = 1;
    resultD[++cntD]=start;

    for (int i=0; i<graph[start].size(); ++i){
        if (visitedD[graph[start][i]]==0){
            dfs(graph[start][i]);
        }
    }
}

void bfs(int start){
    int element;
    visitedB[start] = 1;
    q.push(start);
    
    while(!q.empty()){
        element = q.front();
        resultB[++cntB]=element;
        q.pop();

        for (int i=0; i<graph[element].size(); ++i){
            if (visitedB[graph[element][i]]==0){
                visitedB[graph[element][i]]=1;   
                q.push(graph[element][i]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, V, u, v;
    cin>>N>>M>>V;

    for (int i=0; i<M; ++i){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=N; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    bfs(V);

    for (int i=1; i<=cntD; ++i){
        cout<<resultD[i]<<" ";
    }
    cout<<"\n";

    for (int i=1; i<=cntB; ++i){
        cout<<resultB[i]<<" ";
    }

    return 0;
}