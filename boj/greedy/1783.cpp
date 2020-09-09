#include <iostream>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n, m;
    cin >> n >> m;

    //n이 1이면 움직이지 못한다.
    if(n == 1) 
        cout << 1 << endl;
    //n이 2이면 움직일 수 있는 방법이 두 가지밖에 없으므로
    //최대 3칸밖에 움직이지 못한다.
    else if(n == 2)
        cout << min(4, (m + 1) / 2);
    //n이 3이상일 때
    //m이 6이하이면 모든 방법으로 움직이지 못하므로 최대 3칸 이동할 수 있고
    //m이 6보다 크면 2, 3번 방법 한번씩 사용 후 1, 4번 방법으로만 이동시키면 된다.
    else if(n >= 3)
        cout << (m <= 6 ? min(4, m) : m - 2) << endl;

    return 0;
}