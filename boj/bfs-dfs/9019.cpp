#include <iostream>
#include <string>
#include <queue>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 10000;
bool visited[MAX];
int start, target;

void check(queue<pair<int,string>>& q, int num, string s){
    if(!visited[num]){
        visited[num] = true;
        q.push(make_pair(num, s));
    }
}

string bfs(){
    queue<pair<int, string>> q;
    q.push(make_pair(start, ""));
    visited[start] = true;
    
    while(!q.empty()){
        int here = q.front().first;
        string ans = q.front().second;
        q.pop();
        
        if(here == target) return ans;
        
        check(q, (here * 2) % MAX, ans + "D");
        check(q, (here - 1) < 0 ? 9999 : here - 1, ans + "S");
        check(q, (here % 1000) * 10 + here / 1000, ans + "L");
        check(q, (here % 10) * 1000 + here / 10, ans + "R");
    } 
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        memset(visited, false, sizeof(visited));
        cin >> start >> target;
        cout << bfs() << endl;
    }
    
    return 0;
}