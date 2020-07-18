#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100001;
int adjacent[MAX];
bool visited[MAX];
bool cycle[MAX];
int cnt;

void dfs(int n){
    visited[n] = true;
    int next = adjacent[n];
    if(!visited[next])
        dfs(next);
    //next 노드가 방문은 했지만 사이클 확인이 안 된 경우
    //next 노드에 방문을 했다는 것은 사이클이 성립
    else if(!cycle[next]){
        //사이클의 시작 노드부터 하나씩 방문하며 카운트
        for(int i=next;i!=n;i=adjacent[i])
            cnt++;
        //위 반복문에서는 현재노드를 제외한 나머지 노드를 카운트한다
        //현재노드도 카운트를 해주기위해 1을 더해준다
        cnt++;
    }
    cycle[n] = true;
}

 
int main() {
    int test_case, n;
    cin >> test_case;
 
    while(test_case--){      
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> adjacent[i];

        cnt = 0;
        for (int i=1;i<=n;i++){
            if (!visited[i])
                dfs(i);
        }
        //n에서 사이클(프로젝트 팀을 구성한)에 해당되는 노드를 제외하면
        //팀을 구성하지 못 한 나머지 학생 수가 나온다
        cout << n - cnt << endl;

        memset(adjacent, 0, sizeof(adjacent));
        memset(visited, 0, sizeof(visited));
        memset(cycle, 0, sizeof(cycle));
    }

    return 0;
}
