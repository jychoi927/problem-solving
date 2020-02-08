#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1001;
int dp[MAX];
int cnt[MAX];

int main(){
    fastio;
	
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
	cin >> dp[i];

    int max_cnt = 0;
    for(int i=1;i<=n;i++){
	for(int j=1;j<i;j++){
	    if(dp[i] > dp[j] && cnt[i] < cnt[j]){
		cnt[i] = cnt[j];
	    }
	}
		
	max_cnt = max(max_cnt, ++cnt[i]);
    }

    cout << max_cnt << endl;

    return 0;
}
