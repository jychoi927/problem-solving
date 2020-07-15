#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX=20001;
vector<int> ad_list[MAX];
int visited[MAX];
char node_color[MAX];
int total_node, edge;

void is_BPGraph(){
    for(int i=1;i<=total_node;i++){
        for(int j=0;j<ad_list[i].size();j++){
            if(ad_list[i][j] && node_color[i] == node_color[ad_list[i][j]]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

void dfs(int node){
    for(int i=0;i<ad_list[node].size();i++){
	if(!visited[ad_list[node][i]]){
            visited[ad_list[node][i]] = 1;
            if(node_color[node] == 'b')
                node_color[ad_list[node][i]] = 'r';
            else
                node_color[ad_list[node][i]] = 'b';
            dfs(ad_list[node][i]);
        }
    }
}

int main(){
    int test_case;
    int edge_x, edge_y;
    
    cin >> test_case;
    while(test_case--){
        cin >> total_node >> edge;

        for(int i=0;i<edge;i++){
            cin >> edge_x >> edge_y;
            ad_list[edge_x].push_back(edge_y);
            ad_list[edge_y].push_back(edge_x);
        }

        for(int i=1;i<=total_node;i++){
            if(ad_list[i].size()==0)
                continue;
            if(!visited[i]){
                visited[i] = 1;
                node_color[i] = 'b';
                dfs(i);
            }
        }

        is_BPGraph();

        memset(visited, 0, sizeof(visited));
        memset(node_color, 0, sizeof(node_color));
        for(int i=0;i<MAX;i++){
            ad_list[i].clear();
        }
    }
    
    return 0;
}
