#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
const int MAX = 100;
int A[MAX], B[MAX];
int cache[MAX+1][MAX+1];
int lenA, lenB;

int dp(int idxA, int idxB){
    int &ret = cache[idxA+1][idxB+1];
    if (ret != -1) return ret;
    ret = 0;

    long long a = (idxA == -1 ? NEGINF : A[idxA]);
    long long b = (idxB == -1 ? NEGINF : B[idxB]);
    long long maxElement = max(a, b);

    //현재 선택한 원소보다 더 큰 원소를 찾는다.
    //첫번째 배열의 다음 원소 탐색
    for (int nextA=idxA+1;nextA<lenA;++nextA)
        if (maxElement < A[nextA])
            ret = max(ret, dp(nextA, idxB) + 1);
    //두번재 배열의 다음 원소 탐색
    for (int nextB=idxB+1;nextB<lenB;++nextB)
        if (maxElement < B[nextB])
            ret = max(ret, dp(idxA, nextB) + 1);
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while (_--){
        memset(cache, -1, sizeof(cache));

        cin >> lenA >> lenB;
        for (int i=0;i<lenA;i++)
            cin >> A[i];
        for (int i=0;i<lenB;i++)
            cin >> B[i];

        cout << dp(-1, -1) << endl;
    }
    
    return 0;
}