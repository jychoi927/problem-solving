#include <iostream>

using namespace std;

const int MAX = 1001;
int adjacent[MAX][MAX];
int visited[MAX];
int n,m;

void dfs(int idx){
    for(int i=1;i<=n;i++){
        if(adjacent[idx][i] && !visited[i]){
            visited[i]=1;
            dfs(i);
        }
    }    
}

int main(){
    int cc=0;
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int node1, node2;
        cin >> node1 >> node2;
        adjacent[node1][node2] = 1;
        adjacent[node2][node1] = 1;        
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=1;
            cc++;
            dfs(i);
        }
    }
    
    cout << cc << endl;

    return 0;
}
