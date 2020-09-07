#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    cout << min({(n + m - k) / 3, n / 2, m}) << endl;

    return 0;
}