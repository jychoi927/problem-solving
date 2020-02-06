#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int MAX = 100000;
int dp[2][MAX];

int main(){
    fastio;
    
    int test_case;
    cin >> test_case;
    while(test_case--){
        int n;
        cin >> n;
        
        for(int i=0;i<2;i++)
            for(int j=0;j<n;j++)
                cin >> dp[i][j];
        
        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];
        
        for(int j=2;j<=n;j++){
            dp[0][j] += max(dp[1][j-1], dp[1][j-2]);
            dp[1][j] += max(dp[0][j-1], dp[0][j-2]);
        }
        
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
    
    return 0;    
}
