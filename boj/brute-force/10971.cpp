#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int INF = 987654321;
const int MAX = 10;
int a[MAX][MAX];
bool visited[MAX];
int n, first, ans;

void dfs(int idx, int len, int cnt){
    if(cnt == n && first == idx)
        ans = min(ans, len);

    if(!visited[idx]){
        visited[idx] = true;
        for(int i=0;i<n;i++){
            if(a[idx][i] != 0)
                dfs(i, len + a[idx][i], cnt + 1);
        }
        visited[idx] = false;
    }
}

int main(){
    fastio;

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    ans = INF;
    for(int i=0;i<n;i++){
        first = i;
        dfs(first, 0, 0);
        memset(visited, false, sizeof(visited));
    }

    cout << ans << endl;

    return 0;
}