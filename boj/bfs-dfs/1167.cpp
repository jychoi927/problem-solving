#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 100001;
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
    for(int i=0;i<num;i++){
        cin >> node;
        while(1){
            cin >> edge;
            if(edge == -1)
                break;
            cin >> edge_cost;
            adjacent[node].push_back(make_pair(edge, edge_cost));
        }
    }

    //루트에서부터 가장 긴 거리인 노드부터 구한다
    bfs(1);
    for(int i=2;i<=num;i++){
        if(cost[diameter] < cost[i])
            diameter = i;
    }

    memset(visited, false, sizeof(visited));
    memset(cost, 0, sizeof(cost));

    //루트와 가장 긴 거리의 노드부터 가장 긴 거리의 노드(지름)를 구한다
    bfs(diameter);
    for(int i=1;i<=num;i++)
        if(cost[diameter] < cost[i])
            diameter = i;
    
    cout << cost[diameter] << endl;

    return 0;
}