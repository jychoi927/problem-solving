#include <iostream>
#include <algorithm>
#include <iomanip>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1001;
int n, m;
double cache[MAX][MAX];

double climb(int days, int climbed){
    //m일이 지났을 때 n칸을 올라온 경우 1, 그렇지 않은 경우 0을 반환한다.
    if(days == m) return climbed >= n ? 1 : 0;
    double &ret = cache[days][climbed];
    if(ret != -1) return ret;
    return ret = 0.25 * climb(days+1, climbed+1) + 0.75 * climb(days+1, climbed+2);
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        fill_n(cache[0], MAX*MAX, -1);
        cin >> n >> m;
        cout << fixed;
        cout.precision(10);
        cout << climb(0,0) << endl;
    }

    return 0;
}