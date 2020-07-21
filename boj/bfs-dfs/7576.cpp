#include <iostream>
#include <queue>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX=1000;
int adjacent[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
queue<pair<int,int>> q;

int bfs(){
    int max_day = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(0<=nextX && nextX<m && 0<=nextY && nextY<n){
                //다음 위치의 토마토가 익지 않은 상태이면 현재 위치의 토마토가 익은 날짜에 1을 더함
                if(adjacent[nextY][nextX] == 0){
                    adjacent[nextY][nextX] = adjacent[y][x] + 1;
                    q.push(make_pair(nextX,nextY));
                    max_day = max(max_day, adjacent[nextY][nextX]);
                }
            }
        }
    }
    //날짜를 0이 아닌 1로 시작했기 때문에 1을 빼주는게 최종 정답 날짜
    max_day -= 1;
    return max_day;
}

bool is_ripe(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(adjacent[i][j] == 0)
                return false;
    return true;
}

int main(){
    fastio;

    cin >> m >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> adjacent[i][j];
            //토마토가 들어있는 모든 위치를 큐에 넣음
            if(adjacent[i][j]==1)
                q.push(make_pair(j,i));
        }
    }

    //상자의 모든 토마토가 익은 상태이면 0을 출력
    if(is_ripe()){
        cout << 0 << endl;
        return 0;
    }

    int ans = bfs();

    //모든 탐색을 마치고 아직 익지않은 토마토가 존재하면 -1을 출력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adjacent[i][j] == 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
