#include <iostream>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 101;
int arr[MAX][MAX];
int d[MAX][MAX];
int n;

int dp(int x, int y){
	if (x > n || y > n) return 0;
	if (x == n && y == n) return 1;
	if (d[y][x] != -1) return d[y][x];
	return d[y][x] = (dp(x + arr[y][x], y) || dp(x, y + arr[y][x]));
}

int main(){
	fastio;
	
	int _;
	cin >> _;
	while (_--){
		memset(d, -1, sizeof(d));

		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		int result = dp(1, 1);
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}