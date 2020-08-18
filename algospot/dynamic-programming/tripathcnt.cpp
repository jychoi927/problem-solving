#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 100;
int triangle[MAX][MAX];
int cache[MAX][MAX];
int countCache[MAX][MAX];
int n;

//각 위치에서의 최대 경로를 구한다.
int path(int y, int x){
    if (y == n-1) return triangle[y][x];
    int &ret = cache[y][x];
    if (ret != -1) return ret;
    return ret = triangle[y][x] + max(path(y+1, x), path(y+1, x+1));
}

//최대경로의 개수를 구한다.
int count(int y, int x){
    if(y == n-1) return 1;
    int &ret = countCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if(path(y+1, x+1) >= path(y+1, x)) ret += count(y+1, x+1);
    if(path(y+1, x+1) <= path(y+1, x)) ret += count(y+1, x);
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while (_--){
        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));

        cin >> n;
        for (int i=0;i<n;i++)
            for (int j=0;j<=i;j++)
                cin >> triangle[i][j];

        cout << count(0, 0) << endl;
    }

    return 0;
}