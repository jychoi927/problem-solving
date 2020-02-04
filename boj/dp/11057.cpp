#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int d[1001][10];

int main(){
    fastio;

    int n;
    cin >> n;

    for(int j=0;j<10;j++)
	d[1][j] = 1;
    

    for(int i=2;i<=n;i++){
	for(int j=0;j<10;j++){
	    for(int k=0;k<=j;k++){
		d[i][j] += d[i-1][k];
	    }
            d[i][j] %= 10007;
	}
    }

    int sum = 0;
    for(int i=0;i<10;i++)
	sum += d[n][i];

    cout << sum % 10007 << endl;

    return 0;
}
