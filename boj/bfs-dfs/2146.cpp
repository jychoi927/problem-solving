#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 101;
int adjacent[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int shortest_bridge = 987654321;
int n;

void dfs(int x, int y, int idx){
    visited[y][x] = true;
    adjacent[y][x] = idx;
    
    for(int i=0;i<4;i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if(1 <= nextX && nextX <= n && 1 <= nextY && nextY <=n){
            if(!visited[nextY][nextX] && adjacent[nextY][nextX]){
                dfs(nextX, nextY, idx);
            }
        }
    }
}

int bfs(int idx){
    queue<pair<int,int>> q;
    
    //idx 번호에 해당하는 섬의 모든 곳을 출발점으로 시작해본다
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adjacent[i][j] == idx){
                visited[i][j] = true;
                q.push(make_pair(j,i));
            }
        }
    }
    
    int bridge_cnt = 0;
    while(!q.empty()){
        int queue_size = q.size();
        
        for(int i=0;i<queue_size;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int j=0;j<4;j++){
                int nextX = x + dx[j];
                int nextY = y + dy[j];
                
                if(1 <= nextX && nextX <= n && 1 <= nextY && nextY <=n){
                    //출발 섬에서 가장 짧은 길이로 다른 섬에 도착하면 그 다리의 길이를 반환한다
                    if(adjacent[nextY][nextX] && adjacent[nextY][nextX] != idx){
                        return bridge_cnt;
                    }
                    //바다인 경우 다리를 만들어준다
                    else if(!adjacent[nextY][nextX] && !visited[nextY][nextX]){
                        visited[nextY][nextX] = true;
                        q.push(make_pair(nextX,nextY));
                    }
                }
            }
        }
        bridge_cnt++;        
    }
}

int main(){
    fastio;
    
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> adjacent[i][j];
    
    //dfs로 각 섬에 번호를 매긴다
    int island_num=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(adjacent[i][j] && !visited[i][j])
                dfs(j,i,++island_num);

    //각 섬을 기준으로 bfs로 탐색하여 가장 짧은 다리를 찾아낸다
    for(int i=1;i<=island_num;i++){
        memset(visited, false, sizeof(visited));
        shortest_bridge = min(shortest_bridge, bfs(i));
    }
    
    cout << shortest_bridge << endl;
    
    return 0;
}
