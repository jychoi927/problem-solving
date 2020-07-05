#include <iostream>
#include <algorithm>

using namespace std;

int num[100001];
int dp[100001];

int main(){
    int n;
    int sum;
    cin >> n;

    for(int i=0;i<n;i++){
	cin >> num[i];
    }
    dp[0] = num[0];
    sum = num[0];
    for(int i=1;i<n;i++){
	dp[i] = max(dp[i-1] + num[i], num[i]);
	sum = max(sum,dp[i]);
    }

    cout << sum << endl;
	
    return 0;
}
