#include <iostream>
#include <queue>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int a[1000001];
int F, S, G, U, D;

void bfs(){
    queue<int> q;
    q.push(S);
    a[S] = 1;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        if(here == G) return;

        int up = here + U;
        int down = here - D;

        if(a[up] == 0 && up <= F){
            q.push(up);
            a[up] = a[here] + 1;
        }
        if(a[down] == 0 && down > 0){
            q.push(down);
            a[down] = a[here] + 1;
        }
    }
}

int main(){
    fastio;

    cin >> F >> S >> G >> U >> D;

    bfs();

    if(a[G])
        cout << a[G] - 1 << endl;
    else
        cout << "use the stairs" << endl;

    return 0;
}