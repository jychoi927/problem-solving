#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;
    
    int n, c;
    cin >> n >> c;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int ans = 0, low = 1, high = v[n-1] - v[0];
    
    while(low <= high){
        int mid = (low + high) / 2;
        int len = 1;
        int prev = v[0];
        
        for(int i=1;i<n;i++){
            if(v[i] - prev >= mid){
                len++;
                prev = v[i];
            }
        }
        
        if(len >= c){
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;
    
    return 0;
}