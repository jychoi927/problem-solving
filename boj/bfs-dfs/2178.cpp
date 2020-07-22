#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;
int adjacent[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n, m;

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(1,1));
    visited[1][1] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(1 <= nextX && nextX <= m && 1 <= nextY && nextY <= n){
                if(!visited[nextY][nextX] && adjacent[nextY][nextX]){
                    visited[nextY][nextX] = true;
                    adjacent[nextY][nextX] = adjacent[y][x] + 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%1d", &adjacent[i][j]);
		
    bfs();
    cout << adjacent[n][m] << endl;
    
    return 0;
}
