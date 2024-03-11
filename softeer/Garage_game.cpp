#include <iostream>
#include <queue>

using namespace std;
int N;
int arr[30][15];
bool visited[30][15];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cnt = 0;

queue<pair<int, int>> q;


void bfs(int y, int x){
	q.push(make_pair(y,x));
	visited[y][x] = true;

	while (!q.empty()){
		int curX = q.front().second;
		int curY = q.front().first;
		q.pop();

		for (int i=0; i<4; ++i){
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx<0 || ny<0 || nx>=N || ny>=3*N) continue;
			if (visited[ny][nx]) continue;
			
			if (arr[curY][curX]==arr[ny][nx] && arr[curY][curX] != 0){
				q.push(make_pair(ny, nx));
				cnt++;
			} 
		}
	}
}

void dfs(int y, int x, int my, int py, int mx, int px){
	visited[y][x] = true;

	for (int i=0; i<4; ++i){
		int nx = x + dx[i];
		int ny = x + dy[i];

		if (nx<0 || ny<0 || nx>=N || ny>=3*N) continue;
		if (visited[ny][nx]) continue;
		
		if (arr[y][x]==arr[ny][nx] && arr[y][x] != 0 && i==0){
			dfs(ny, nx, my, py, mx+1, px);
		}
		else if (arr[y][x]==arr[ny][nx] && arr[y][x] != 0 && i==1){
			dfs(ny, nx, my, py, mx, px+1);
		} 
		else if (arr[y][x]==arr[ny][nx] && arr[y][x] != 0 && i==2){
			dfs(ny, nx, my+1, py, mx, px);
		}
		else if (arr[y][x]==arr[ny][nx] && arr[y][x] != 0 && i==3){
			dfs(ny, nx, my, py+1, mx, px);
		}
	}
}


int main(int argc, char** argv)
{
	cin>>N;

	for (int i=0; i<3*N; ++i){
		for (int j=0; j<N; ++j){
			cin>>arr[i][j];
		}
	}

	for (int i=3*N-1; i>=0; --i){
		for (int j=0; j<N; ++j){
			for (int k=0; k<3; ++k){
				dfs(i, j, 0, 1, 0, 1);



			}
			// bfs(i, j);
		}
	}

	cout<<cnt<<"\n";

	return 0;
}