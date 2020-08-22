#include <iostream>
#include <cstring>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

double cache[51][101];
int connected[51][51];
int deg[51];
int n,d,p,q;

//감옥에서부터 시작하지 않고 
//다른 마을에서부터 시작하여 감옥으로 도착하는 경우를 확인.
double search(int here, int days){
    if(days == 0) return (here == p ? 1.0 : 0.0);
    
    double &ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    //현재위치와 인접한 경로를 모두 방문하여 d일째에 감옥에 위치할 확률을 구한다.
    for(int there=0;there<n;++there)
        if(connected[here][there])
            ret += search(there, days-1) / deg[there];
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        memset(cache, -1, sizeof(cache));
        memset(deg, 0, sizeof(deg));

        cin >> n >> d >> p;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> connected[i][j];
                //i번째 마을과 연결된 마을의 개수를 더해준다.
                deg[i] += connected[i][j];
            }
        }

        cin >> q;
        while(q--){
            int h;
            cin >> h;
            cout.precision(8);
            cout << search(h, d) << " ";
        }
        cout << endl;
    }
}