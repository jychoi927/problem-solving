#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int INF = 987654321;
string N;
int d[10002];

//N[a..b] 구간의 난이도를 반환한다.
int classify(int a, int b){
    //N[a..b] 구간의 문자열
    string M = N.substr(a, b-a+1);

    //문자열의 모든 값이 같은 경우
    if(M == string(M.size(), M[0]))
        return 1;

    //등차수열 확인
    bool progressive = true;
    for(int i=0;i<M.size()-1;i++)
        if(M[i+1] - M[i] != M[1] - M[0])
            progressive = false;
    //등차수열이고 공차가 1 이나 -1 인 경우
    if(progressive && abs(M[1] - M[0]) == 1)
        return 2;

    //두 수가 번갈아 나오는 경우
    bool alternating = true;
    for(int i=0;i<M.size();i++)
        if(M[i] != M[i%2])
            alternating = false;
    if(alternating)
        return 4;

    //공차가 1이 아닌 등차수열인 경우
    if(progressive)
        return 5;

    //나머지
    return 10;
}

int dp(int begin){
    if(begin == N.size())
        return 0;
    int &ret = d[begin];
    if(ret != -1)
        return ret;
    ret = INF;
    
    //조각의 길이는 3~5
    //해당 조각의 난이도와 나머지 조각들의 값을 구한다.
    for(int L=3;L<=5;L++)
        if(begin+L <= N.size())
            ret = min(ret, dp(begin + L) + classify(begin, begin + L - 1));
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        memset(d, -1, sizeof(d));
        cin >> N;
        cout << dp(0) << endl;
    }

    return 0;
}
