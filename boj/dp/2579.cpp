#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num[301];
    int dp[301];
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
	cin >> num[i];
    }

    dp[0] = 0;
    dp[1] = num[1];
    dp[2] = num[1] + num[2];

    for(int i=3;i<=n;i++){
	dp[i] = max(num[i] + num[i-1] + dp[i-3], num[i] + dp[i-2]);
    }

    cout << dp[n] << endl;
    
    return 0;
}
