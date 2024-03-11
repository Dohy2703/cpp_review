#include <iostream>
#include <vector>

using namespace std;
int N, ret;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    vector<int> v(N);
    vector<int> max_v(N);

    for (int i=0; i<N; ++i){
        cin>>v[i];
    }

    ret = max_v[0] = v[0];
    for (int i=1; i<v.size(); ++i){ 
        max_v[i] = max(max_v[i-1]+v[i], v[i]);
        ret = max(max_v[i], ret); 
    }

    cout<<ret;

    return 0;
}
