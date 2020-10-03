#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 2001;
int a[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(0 <= nx && nx < MAX && 0 <= ny && ny < MAX){
            if(a[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    fastio;
    
    int n, x1, x2, y1, y2;
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        //-500 ~ 500의 범위는 0 ~ 1000으로 변경되어야 한다.
        //또한 사각형과 내부의 작은 사각형이 겹치게 두지 않기위해
        //범위를 두 배(0 ~ 2000)로 늘려준다.
        x1 = (x1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y1 = (y1 + 500) * 2;
        y2 = (y2 + 500) * 2;
        
        //사각형을 그려준다.
        for(int i=y1;i<=y2;i++){
            a[x1][i] = 1;
            a[x2][i] = 1;
        }
        for(int i=x1;i<=x2;i++){
            a[i][y1] = 1;
            a[i][y2] = 1;
        }
    }
    
    int ans = 0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(a[i][j] && !visited[i][j]){
                visited[i][j] = true;
                dfs(i, j);
                ans++;
            }
        }
    }
    
    //시작점(1000, 1000)에서는 연필을 내린상태로 시작하므로
    //시작점이 사각형에 포함되면 한 번 빼줘야한다.
    if(visited[1000][1000]) ans--;
    cout << ans << endl;
    
    return 0;
}