#include <iostream>
#include <vector>
#include <algorithm>

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
    
    sort(v.begin(),v.end());
    
    int ans = 0;
    //전체 순열을 돌면서 최댓값을 구한다.
    do{
        int sum = 0;
        for(int i=0;i<n-1;i++)
            sum += abs(v[i] - v[i+1]);
        ans = max(ans, sum);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans << endl;

    return 0;
}