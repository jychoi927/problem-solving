#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int d[101][10];

int main(){
    fastio;

    int n;
    cin >> n;

    for(int j=0;j<10;j++)
	d[1][j] = 1;
    

    for(int i=2;i<=n;i++){
	for(int j=0;j<10;j++){
	    if(j==0)
		d[i][j] = d[i-1][1];
	    else if(j==9)
		d[i][j] = d[i-1][8];
	    else
		d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
	}
    }

    int sum = 0;
    for(int j=1;j<10;j++)
	sum = (sum + d[n][j]) % 1000000000;

    cout << sum << endl;

    return 0;
}
