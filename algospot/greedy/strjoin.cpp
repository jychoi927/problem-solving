#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int concat(const vector<int>& lengths){
    //우선순위 큐를 사용해서 작은 값을 항상 top쪽으로 위치시킨다.
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<lengths.size();i++)
        pq.push(lengths[i]);
    
    int ret = 0;
    while(pq.size() > 1){
        //가장 잛은 문자열 두 개를 찾아서 합치고 큐에 넣는다.
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        pq.push(min1 + min2);
        ret += min1 + min2;
    }
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];
        
        cout << concat(v) << endl;
    }

    return 0;
}