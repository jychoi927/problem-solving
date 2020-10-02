#include <iostream>
#include <string>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 100;
const int MAX_LEN = 80;
char arr[MAX][MAX];
int d[MAX][MAX][MAX_LEN];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m, k;
string target;

int dfs(int x, int y, int idx){
    if(d[x][y][idx] != -1) return d[x][y][idx];
    if(idx == target.length()) return 1;
    
    d[x][y][idx] = 0;
    
    for(int i=0;i<4;i++){
        for(int j=1;j<=k;j++){
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
                if(arr[nx][ny] == target[idx])
                    d[x][y][idx] += dfs(nx, ny, idx + 1);
        }
    }
    
    return d[x][y][idx];
}

int main(){
    fastio;

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    cin >> target;
    
    int ans = 0;
    memset(d, -1, sizeof(d));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(arr[i][j] == target[0])
                ans += dfs(i, j, 1);
    
    cout << ans << endl;
    
    return 0;
}