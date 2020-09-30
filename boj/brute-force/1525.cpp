#include <iostream>
#include <queue>
#include <set>
#include <string>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

string start, target = "123456780";
set<string> visited;

int bfs(){
    queue<pair<string,int>> q;
    q.push(make_pair(start, 0));
    visited.insert(start);
    
    while(!q.empty()){
        string curStr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(curStr == target) return cnt;
        
        int z = curStr.find('0');
        int x = z / 3;
        int y = z % 3;
        
        for(int i=0;i<4;i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if(0 <= nextX && nextX < 3 && 0 <= nextY && nextY < 3){
                string nextStr = curStr;
                swap(nextStr[x * 3 + y], nextStr[nextX * 3 + nextY]);
                if(visited.find(nextStr) == visited.end()){
                    visited.insert(nextStr);
                    q.push(make_pair(nextStr, cnt + 1));
                }
            }
        }
    }
    return -1;
}

int main(){
    fastio;

    for(int i=0;i<9;i++){
        char num;
        cin >> num;
        start += num;
    }
    
    cout << bfs() << endl;

    return 0;
}