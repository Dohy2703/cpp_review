#include<iostream>

using namespace std;
int N, K;
string str;
int cnt;

int main(int argc, char** argv)
{
	cin>>N>>K>>str;

	for (int i=0; i<N; ++i){
		if (str[i]=='P'){
			for (int j=i-K; j<=i+K; ++j){
				if (j<0 || j>=str.size() || i==j) continue;
				if (str[j]=='H'){
					str[j]='X';
					cnt++;
					break;
				}
			}
		}
	}

	cout<<cnt;

	return 0;
}