#include <iostream>
#include <vector>

using namespace std;
int N, M, u, v;
vector<int> weight(100001);
vector<int> strongest(100001);
int cnt = 0;

int main(int argc, char** argv)
{
	cin>>N>>M;

	for (int i=1; i<=N; ++i){
		cin>>weight[i];
	}

	for (int i=1; i<=N; ++i){
		strongest[i]=1;
	}

	for (int i=0; i<M; ++i){
		cin>>u>>v;

		if (weight[u]>weight[v]) strongest[v]=0;
		else if (weight[v]>weight[u]) strongest[u] = 0;
		else{
			strongest[u] = 0;
			strongest[v] = 0;
		}
	}

	for (int i=1; i<=N; ++i){
		if (strongest[i]==1) {
			cnt++;
			// cout<<i<<" ";
		}
	}
	// cout<<"\n";

	cout<<cnt;

	return 0;
}