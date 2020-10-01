#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 201;
int size_a,size_b,size_c;
bool visited[MAX][MAX][MAX];
vector<int> ans;

void bfs(){
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, size_c)));

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if(visited[a][b][c]) continue;
        visited[a][b][c] = true;

        //a가 비어있는 경우 c에 들어있는 물의 양을 정답에 넣는다.
        if(a == 0) ans.push_back(c);

        //a에 물을 채워넣는다.
        if (a + b > size_a)
            q.push(make_pair(size_a, make_pair(b + a - size_a, c)));
        else
            q.push(make_pair(b + a, make_pair(0, c)));
        
        if (a + c > size_a)
            q.push(make_pair(size_a, make_pair(b, c + a - size_a)));
        else
            q.push(make_pair(c + a, make_pair(b, 0)));

        //b에 물을 채워넣는다.
        if(a + b > size_b)
            q.push(make_pair(a + b - size_b, make_pair(size_b, c)));
        else
            q.push(make_pair(0, make_pair(a + b, c)));

        if (b + c > size_b)
            q.push(make_pair(a, make_pair(size_b, c + b - size_b)));
        else
            q.push(make_pair(a, make_pair(c + b, 0)));
        
        //c에 물을 채워넣는다.
        if (a + c > size_c)
            q.push(make_pair(a + c - size_c, make_pair(b, size_c)));
        else
            q.push(make_pair(0, make_pair(b, a + c)));

        if (b + c > size_c)
            q.push(make_pair(a, make_pair(b + c - size_c, size_c)));
        else
            q.push(make_pair(a, make_pair(0, b + c)));
    }
}

int main(){
    fastio;

    cin >> size_a >> size_b >> size_c;
    
    bfs();
    sort(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << endl;
    
    return 0;
}