#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 10001;
bool isPrime[MAX];
int visited[MAX];
int start,target;

int change_digit(int num, int digit, int next){
    int change = num;

    if(digit == 1){
        change -= (num / 1000) * 1000;
        change += (next * 1000);
    }
    else if(digit == 2){
        change -= ((num / 100) % 10) * 100;
        change += (next * 100);
    }
    else if(digit == 3){
        change -= ((num / 10) % 10) * 10;
        change += (next * 10);
    }
    else{
        change -= num % 10;
        change += next;
    }

    return change;
}

int bfs(){
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        if(here == target)
            return visited[here];

        //천의 자리부터 하나씩 숫자를 바꿔가며 소수를 방문한다.
        for(int i=1;i<=4;i++){
            for(int j=0;j<10;j++){
                int next = change_digit(here, i, j);
                if(next < 1000) continue;
                if(isPrime[next] && visited[next] == 0){
                    visited[next] = visited[here] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

void eratosthenes(){
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;
    int sqrtn = int(sqrt(MAX));
    for(int i=2;i<=sqrtn;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    fastio;

    eratosthenes();
    
    int _;
    cin >> _;
    while(_--){
        cin >> start >> target;
        int result = bfs();
        if (result == -1)
            cout << "Impossible" << endl;
        else
            cout << result - 1 << endl;
    }

    return 0;
}