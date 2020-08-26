#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 10000;
int e[MAX];
int m[MAX];
int n;

int heat(){
    vector<pair<int,int>> order;
    //도시락 먹는 시간을 내림차순으로 정렬한다.
    for(int i=0;i<n;++i)
        order.push_back(make_pair(-e[i], i));
    sort(order.begin(), order.end());

    int ret = 0, beginEat = 0;
    for(int i=0;i<n;++i){
        int box = order[i].second;
        //도시락을 데우는 시간을 더한다.
        beginEat += m[box];
        //이전 도시락을 먹는데 까지 걸리는 시간과
        //현재 도시락을 데워서 먹는데까지 걸리는 시간을 비교한다.
        //이전 도시락을 먹는데 걸리는 시간이 더 오래 걸리면 
        //그전에 현재 도시락을 데워서 먹을 수 있다는 의미이기 때문에 포함되지 않아도 된다.
        ret = max(ret, beginEat + e[box]);
    }
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        cin >> n;
        for(int i=0;i<n;++i)
            cin >> m[i];
        for(int i=0;i<n;++i)
            cin >> e[i];
        
        cout << heat() << endl;
    }

    return 0;
}