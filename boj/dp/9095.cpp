#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int d[11];
int dp(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(d[n]!=0) return d[n];
    return d[n] = dp(n-1) + dp(n-2) + dp(n-3);
}

int main(){
    fastio;
    
    int test_case,n;
    cin >> test_case;
    while(test_case--){
        cin >> n;
        cout << dp(n) << endl;
    }
    
    return 0;
}
