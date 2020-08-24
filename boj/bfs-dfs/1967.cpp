#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 10001;
vector<pair<int, int>> adjacent[MAX];
bool visited[MAX];
int cost[MAX];

void bfs(int num){
    queue<int> q;
    q.push(num);
    visited[num] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0;i<adjacent[x].size();i++){
            int next = adjacent[x][i].first;
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                cost[next] = cost[x] + adjacent[x][i].second;
            }
        }
    }
}

int main(){
    fastio;
    
    int num, node, edge, edge_cost;
    int diameter = 1;
    
    cin >> num;
    for(int i=0;i<num-1;i++){
        cin >> node >> edge >> edge_cost;
        adjacent[node].push_back(make_pair(edge,edge_cost));
        adjacent[edge].push_back(make_pair(node,edge_cost));
    }
    
    bfs(1);
    for(int i=2;i<=num;i++)
        if(cost[diameter] < cost[i])
            diameter = i;
        
    memset(visited,false,sizeof(visited));
    memset(cost,0,sizeof(cost));
    
    bfs(diameter);
    for(int i=1;i<=num;i++)
        if(cost[diameter] < cost[i])
            diameter = i;
    
    cout << cost[diameter] << endl;
}