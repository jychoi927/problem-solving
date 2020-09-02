#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1000001;
long long tree[MAX];

int main(){
    fastio;
    
    int n, m;
    long long len, low = 1, mid, high = 0, ans = 0;

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> tree[i];
        if (high < tree[i])
            high = tree[i];
    }

    //길이 1부터 가장 긴 나무 길이만큼 이분 탐색
    while(low <= high){
        mid = (low + high) / 2;
        len = 0;

        //mid길이만큼 나무들을 잘랐을 때 잘린 나무의 길이
        for (int i=1;i<=n;i++)
            if(tree[i] >= mid)
                len += tree[i] - mid;

        //잘린 나무의 길이가 필요 길이 m을 넘는 경우
        //더 높은 mid가 나올 수 있으므로 low를 높여서 다시 탐색
        if(len >= m){
            if(mid > ans)
                ans = mid;
            low = mid + 1;
        }
        //잘린 나무의 길이가 m을 넘지 못하면 길이를 줄여서 다시 탐색
        else
            high = mid - 1;
    }

    cout << ans << endl;

    return 0;
}