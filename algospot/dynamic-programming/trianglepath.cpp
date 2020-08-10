#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 101;
int arr[MAX][MAX];
int d[MAX][MAX];
int n;

int dp(int x, int y){
	if (y == n)
		return arr[y][x];
	if (d[y][x] != -1)
		return d[y][x];
	return d[y][x] = arr[y][x] + max(dp(x, y+1), dp(x+1, y+1));
}

int main(){
    fastio;

	int _;
	cin >> _;
	while (_--){
		memset(d, -1, sizeof(d));

		cin >> n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=i;j++)
				cin >> arr[i][j];

		cout << dp(1, 1) << endl;
	}

	return 0;
}
