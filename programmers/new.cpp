#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int day, default_days;

    cin>>day;

    default_days = floor(357 / 7) * 2;
    
    if (day==7 || day==6){
        default_days += 3;
    }
    else {
        default_days += 2;
    }

    cout<<default_days;

    return 0;
}
