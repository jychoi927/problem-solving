#include <iostream>

using namespace std;

int main(){
    int E, S, M;
    cin >> E >> S >> M;

    int e = 0, s = 0, m = 0, ans = 0;
    while(1){
        if(e > 15) e = 1;
        if(s > 28) s = 1;
        if(m > 19) m = 1;
        if(e == E && s == S && m == M) break;
        e++;s++;m++;ans++;
    }

    cout << ans << endl;

    return 0;
}