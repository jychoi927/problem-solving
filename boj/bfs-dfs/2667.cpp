#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 26;
int N;
int adjacent[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int house_cnt=0;

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int nextX = x+dx[i];
        int nextY = y+dy[i];
        
        if(0<nextX && nextX<=N && 0<nextY && nextY<=N){
            if(adjacent[nextX][nextY] && !visited[nextX][nextY]){
                visited[nextX][nextY] = 1;
                house_cnt++;
                dfs(nextX,nextY);
            }
        }
    }
}

int main(){
    vector<int> houses;
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            scanf("%1d",&adjacent[i][j]);
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(adjacent[i][j] && !visited[i][j]){
                visited[i][j] = 1;
                house_cnt++;
                dfs(i,j);
                houses.push_back(house_cnt);
                house_cnt=0;
            }
        }
    }
    
    sort(houses.begin(), houses.end());
    
    cout << houses.size() << endl;
    for(int i=0;i<houses.size();i++)
        cout << houses[i] << endl;
    
    return 0;
}

