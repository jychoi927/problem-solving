#include <iostream>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 100001;
vector<int> adjacent[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int node){
    visited[node] = true;
    
    //node가 가지고 있는 child를 탐색하면서
    for(int i=0;i<adjacent[node].size();i++){
        //child에 방문하지 않았으면 child에 parent의 번호를 적어주고 
        //해당 child를 parent로서 dfs 탐색
        if(!visited[adjacent[node][i]]){
            parent[adjacent[node][i]] = node;
            dfs(adjacent[node][i]);
        }
    }
}

int main(){
    fastio;
    
    int n, x, y;
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    
    dfs(1);
    
    for(int i=2;i<=n;i++)
        cout << parent[i] << endl;
    
    return 0;
}