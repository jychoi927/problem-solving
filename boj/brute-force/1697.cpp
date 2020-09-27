#include <iostream>
#include <queue>

#define endl '\n'
#define fastio cin.sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int MAX = 100001;
bool visited[MAX];

int minSecond(int n, int k){
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty()){
        int curLoc = q.front().first;
        int curSec = q.front().second;
        q.pop();

        if (curLoc == k)
            return curSec;

        //앞으로 한 칸 이동
        if(curLoc + 1 < MAX && !visited[curLoc + 1]){
            q.push(make_pair(curLoc + 1, curSec + 1));
            visited[curLoc + 1] = true;
        }
        //뒤로 한 칸 이동
        if(curLoc - 1 >= 0 && !visited[curLoc - 1]){
            q.push(make_pair(curLoc - 1, curSec + 1));
            visited[curLoc - 1] = true;
        }
        //앞으로 (현재위치 x 2)칸 이동
        if(curLoc * 2 < MAX && !visited[curLoc * 2]){
            q.push(make_pair(curLoc * 2, curSec + 1));
            visited[curLoc * 2] = true;
        }
    }
}

int main(void){
    fastio;

    int n, k;
    cin >> n >> k;
    cout << minSecond(n, k) << endl;

    return 0;
}