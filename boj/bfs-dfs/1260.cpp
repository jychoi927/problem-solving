#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;
int N,M,V;

void dfs(int idx){
    cout << idx << " ";
    
    for(int i=1;i<=N;i++){
        if(adjacent[idx][i] && !visited[i]){
            visited[i] = 1;
            dfs(i);
        }
    }
    
}
void bfs(int idx){
    q.push(idx);
    visited[idx] = 1;
    
    while(!q.empty()){
        idx = q.front();
        q.pop();
        
        cout << idx << " ";
        
        for(int i=1;i<=N;i++){
            if(adjacent[idx][i] && !visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> N >> M >> V;
    
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        adjacent[from][to] = 1;
        adjacent[to][from] = 1;
    }
    
    visited[V]=1;
    dfs(V);
    cout << endl;
    
    memset(visited, false, sizeof(visited));
    bfs(V);
    cout << endl;

    return 0;
}
