#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int left = 0, right = n - 1, ans = 0;

    //0 이하의 수는 곱해준다.
    while(left < right && v[left] < 1 && v[left + 1] < 1){
        ans += v[left] * v[left+1];
        left += 2;
    }
    //2 이상의 수는 곱해준다.
    while(right > 0 && v[right] > 1 && v[right - 1] > 1){
        ans += v[right] * v[right - 1];
        right -= 2;
    }
    //남은 수는 더해준다.
    while(left <= right)
        ans += v[right--];

    cout << ans << endl;

    return 0;
}