#include<iostream>
#include<vector>

using namespace std;
int N;
int arr[1001][4];
int DP[1001][2];
vector<int> vN(2);

int main(int argc, char** argv)
{
	cin>>N;

	if (N==1){
		cin>>arr[0][0]>>arr[0][1]>>arr[0][2]>>arr[0][3];
		cin>>vN[0]>>vN[1];
		cout<<min(arr[0][0], arr[0][1]);
		return 0;
	}

	for(int i=0; i<N-1; ++i){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
	}
	cin>>vN[0]>>vN[1];


	for (int i=0; i<N-1; ++i){
		DP[i+1][0] = min(DP[i][0]+arr[i][0], DP[i][1]+arr[i][1]+arr[i][3]);
		DP[i+1][1] = min(DP[i][1]+arr[i][1], DP[i][0]+arr[i][0]+arr[i][2]);
		// cout<<DP[i+1][0]<<" "<<DP[i+1][1]<<"\n";
	}
	// cout<<DP[N-1][0]<<" "<<DP[N-1][1]<<"\n";

	DP[N][0] = DP[N-1][0]+vN[0];
	DP[N][1] = DP[N-1][1]+vN[1];

	// cout<<DP[N][0]<<DP[N][1];

	int answer;
	answer = min(DP[N][0], DP[N][1]);
	cout<<answer;
	
	return 0;
}