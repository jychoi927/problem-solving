#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int a[10];

int main(){
    fastio;

    int n, k;
    int ans = 0;

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=n-1;i>=0;i--){
        //i번째 동전이 k 이하이면 해당 동전을 k에 나눠 개수를 구하고 k에서 빼준다.
        if (k >= a[i]){
            ans += k / a[i];
            k %= a[i];
        }
    }

    cout << ans << endl;

    return 0;
}