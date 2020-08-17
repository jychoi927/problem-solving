#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int d[101];

int dp(int n){
    if(n <= 1) return 1;
    if(d[n] != 0) return d[n];
    return d[n] = (dp(n-1) + dp(n-2)) % 1000000007;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        cout << dp(n) << endl;
    }
    
    return 0;
}