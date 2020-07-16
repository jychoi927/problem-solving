#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1001;
bool visited[MAX];
int arr[MAX];

void dfs(int idx){
    visited[idx] = true;
    if(!visited[arr[idx]])
        dfs(arr[idx]);
}

int main(){
    int test_case;
    cin >> test_case;
    
    int node, cnt;

    while(test_case--){
        cnt = 0;
        cin >> node;

        for(int i=1;i<=node;i++)
            cin >> arr[i];

        for(int i=1;i<=node;i++){
            if(!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        
        cout << cnt << endl;
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));
    }
    
    return 0;
}
