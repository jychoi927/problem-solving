#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int INF = 987654321;
const int MAX = 101;
int d[MAX][11];
int A[MAX], pSum[MAX], pSqSum[MAX];
int n, s;

void precalc(){
    sort(A,A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for(int i=1;i<n;i++){
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
}

//A[lo..hi] 구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산한다.
int minError(int lo, int hi){
    //구간의 합을 구한다.
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
    //구간합과 구간의 길이를 나눈 값으로 해당 구간의 양자값을 구한다.
    int m = int(0.5 + (double)sum / (hi-lo+1));
    //구간의 오차를 구한다.
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}

int quantize(int from, int parts){
    //모든 숫자를 양자화했을 때
    if(from == n) return 0;
    //숫자는 아직 남았는데 남는 조각 수가 없을 때는 포함을 시키면 안된다.
    if(parts == 0) return INF;
    int &ret = d[from][parts];
    if(ret != -1) return ret;
    ret = INF;

    //조각의 길이를 변화시켜가며 최소치를 찾는다.
    for(int partSize=1;from+partSize<=n;++partSize)
        ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));

    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        memset(d, -1, sizeof(d));

        cin >> n >> s;
        for(int i=0;i<n;i++)
            cin >> A[i];
        precalc();

        cout << quantize(0,s) << endl;
    }

    return 0;
}