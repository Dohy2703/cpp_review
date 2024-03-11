#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    struct compare{
        bool operator()(int a, int b){
            if (abs(a) == abs(b)) return a>b;
            else return abs(a) > abs(b);
        }
    };

    priority_queue<int, vector<int>, compare> pq;
    for (int i=0; i<N; ++i){
        int x;
        cin>>x;

        if (pq.empty() && x==0) cout<<0<<"\n";
        else if (x!=0) pq.push(x);
        else if (x==0) {
            cout<<pq.top()<<"\n";
            pq.pop();
        }
    }

    return 0;
}