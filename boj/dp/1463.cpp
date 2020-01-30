#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1000001;
int d[MAX];

int main(){
    fastio;

    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
	d[i] = d[i-1] + 1;
	if(i % 2 == 0) d[i] = min(d[i], d[i/2] + 1);
	if(i % 3 == 0) d[i] = min(d[i], d[i/3] + 1);
    }
    cout << d[n] << endl;

    return 0;
}
