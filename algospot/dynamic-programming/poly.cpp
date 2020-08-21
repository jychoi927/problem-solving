#include <iostream>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MOD = 10000000;
int cache[101][101];

int poly(int n, int first){
    if(n == first) return 1;

    int &ret = cache[n][first];
    if(ret != -1) return ret;
    ret = 0;

    //현재 행에 사각형을 1개부터 남는 사각형만큼 놓는 경우를 모두 구해서 더해준다.
    for(int second=1;second<=n-first;++second){
        //바로 윗 줄에 first개의 사각형이 놓여있을 때
        //현재 줄에 second개의 사각형을 놓으려면
        //second + first - 1가지 방법만큼 놓을 수 있다.
        int add = second + first - 1;
        //다음 행에서 올 수 있는 방법을 add 개수만큼 곱해준다.
        add *= poly(n-first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        memset(cache, -1, sizeof(cache));

        int n;
        cin >> n;
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += poly(n,i);
            sum %= MOD;
        }
        cout << sum << endl;
    }
}