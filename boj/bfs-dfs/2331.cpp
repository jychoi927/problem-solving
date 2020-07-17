#include <iostream>
#include <cmath>

using namespace std;

const int MAX=300000;
int visited[MAX];
int p;

void dfs(int num){
    visited[num]++;
    if(visited[num]==3)
        return;
    int sum=0;
    while(num){
        sum += pow(num%10,p);
        num /= 10;
    }
    dfs(sum);
}

int main(){
    int n, cnt=0;
    cin >> n >> p;
    
    dfs(n);
    
    for(int i=0;i<MAX;i++)
        if(visited[i]==1)
            cnt++;
    
    cout << cnt << endl;
    
    return 0;
}
