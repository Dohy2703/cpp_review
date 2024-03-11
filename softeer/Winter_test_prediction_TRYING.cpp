#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;
int N, M;
int arr[101][101];
int visited[101][101];
int cnt=0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


queue<pair<int, int>> q;

void bfs(){
	q.push(make_pair(0,0));
	visited[0][0] = 1;

	while (!q.empty()){
		int curX = q.front().second;
		int curY = q.front().first;
		q.pop();
		
		for (int i=0; i<4; ++i){
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx<0 || ny<0 || nx>=M || ny>=N) continue;
			if (arr[ny][nx]==1) visited[ny][nx]++;
			else if (visited[ny][nx]==0) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = 1;
			}
		}
	}

	for (int i=0; i<N; ++i){
		for (int j=0; j<M; ++j){
			if (visited[i][j]>=2) arr[i][j]=0;
		}
	}
}

int main(int argc, char** argv)
{
	cin>>N>>M;

	for (int i=0; i<N; ++i){
		for (int j=0; j<M; ++j){
			cin>>arr[i][j];
		}
	}

	int answer = 0;
	while (true){
		cnt = 0;
		bfs();

		for (int i=0; i<N; ++i){
			for (int j=0; j<M; ++j){
				if (arr[i][j]==1) cnt++;
			}
		}

		if (cnt==0) break;
		answer++;
		memset(arr, 0, sizeof(arr));
	}

	cout<<answer;

	return 0;
}