#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1001;
int d[MAX];

int dp(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(d[n] != 0) return d[n];
    return d[n] = (dp(n-1) + dp(n-2)) % 10007;
}

int main(){
    fastio;

    int n;
    cin >> n;
    
    cout << dp(n) << endl;

    return 0;
}
