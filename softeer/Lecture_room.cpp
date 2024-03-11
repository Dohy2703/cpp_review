#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> v;
int N, startT, endT;

int main(int argc, char** argv)
{
	cin>>N;
	
	for (int i=0; i<N; ++i){
		cin>>startT>>endT;

		v.push_back(make_pair(endT, startT));
	}
	
	sort(v.begin(), v.end());

	int cur_end = v[0].first;
	int cnt = 1;

	for (int i=0; i<N; ++i){
		if (v[i].second >= cur_end){
			cnt++;
			cur_end = v[i].first;
		}
	}

	cout<<cnt;

	return 0;
}