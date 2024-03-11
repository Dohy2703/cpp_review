#include<iostream>
#include <vector>
#include<math.h>

using namespace std;
int N, K, u, v_;

int main(int argc, char** argv)
{
	cin>>N>>K;
	vector<int> v;

	for (int i=0; i<N; ++i){
        int tmp;
		cin>>tmp;
        v.push_back(tmp);
	}

	for (int i=0; i<K; ++i){
		cin>>u>>v_;

		float tmp_sum = 0;
		for (int j=u-1; j<=v_-1; ++j){
			tmp_sum += (float)v[j];
		}
		tmp_sum /= v_-u+1;
		tmp_sum = round(tmp_sum*100.)/100.;

        cout<<fixed;
        cout.precision(2);
		cout<<tmp_sum<<"\n";
	}

	return 0;
}