#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n, m, compare;

    cin >> n;
    vector<int> cards(n);

    for (int i=0;i<n;i++)
        cin >> cards[i];

    sort(cards.begin(), cards.end());

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> compare;
        cout << upper_bound(cards.begin(), cards.end(), compare) - lower_bound(cards.begin(), cards.end(), compare) << " ";
    }
    cout << "\n";

    return 0;
}