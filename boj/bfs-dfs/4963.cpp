#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 51;
int adjacent[MAX][MAX];
int visited[MAX][MAX];
//대각선도 포함이므로 총 8방향을 탐색
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int x, y;

void dfs(int cur_x, int cur_y){
    for(int i=0;i<8;i++){
        int nextX = cur_x + dx[i];
        int nextY = cur_y + dy[i];

        if(1 <= nextX && nextX <= x && 1 <= nextY && nextY <= y){
            if(!visited[nextX][nextY] && adjacent[nextX][nextY]){
                visited[nextX][nextY] = 1;
                dfs(nextX,nextY);
            }
        }
    }
}

int main(){

    while(cin >> y >> x && x && y){

        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                cin >> adjacent[i][j];
			
        int cnt = 0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                //방문하지 않은 땅을 발견하면 섬의 개수에 1을 더해주고
                //dfs로 현재 위치한 섬에서 이동가능한 모든 땅을 탐색
                if(!visited[i][j] && adjacent[i][j]){
                    visited[i][j] = 1;
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        cout << cnt << endl;

        memset(adjacent,0,sizeof(adjacent));
        memset(visited,0,sizeof(visited));
    }
    
    return 0;
}
