#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];

    //시간이 가장 작게 걸리는 순서대로 정렬을 하고
    //자기를 포함한 앞쪽 인원들의 시간을 모두 더해준다.
    sort(v.begin(), v.end());
    for(int i=1;i<=n;i++)
        ans += v[n-i] * i;
    cout << ans << endl;

    return 0;
}