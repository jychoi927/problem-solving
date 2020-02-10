#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1001;
int num[MAX];
int dp[MAX];

int main(){
    fastio;
	
    int n;
    int max_num = 0;

    cin >> n;
    for(int i=1;i<=n;i++)
	cin >> num[i];
	
    for(int i=1;i<=n;i++){
	dp[i] = num[i];
	for(int j=1;j<i;j++){
	    if(num[i] > num[j]){
		dp[i] = max(dp[i], dp[j] + num[i]);
	    }
	}
	max_num = max(max_num,dp[i]);
    }

    cout << max_num << endl;

    return 0;
}
