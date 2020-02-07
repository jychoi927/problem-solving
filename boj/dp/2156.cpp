#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 10001;
int wine[MAX];
int dp[MAX];

int main(){
    fastio;
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> wine[i];
    
    
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    
    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-3]+wine[i-1]+wine[i]);
        dp[i] = max(dp[i],dp[i-2]+wine[i]);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
