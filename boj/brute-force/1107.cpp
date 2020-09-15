#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 1000000;
const int INF = 9876543;
int n, m;

//해당 숫자에 고장난 버튼이 있는지 확인한다.
bool check_num(int num, vector<int> v){
    string s = to_string(num);
    for(int i=0;i<s.length();i++)
        for(int j=0;j<v.size();j++)
            if(s[i] - '0' == v[i])
                return false;

    return true;
}

int move_channel(vector<int> v){
    int idx = 0, ans = INF;
    for(int i=0;i<=MAX;i++){
        //고장난 버튼이 없는 경우 해당 번호에서
        //이동하려는 번호까지의 최소 버튼 수를 찾는다.
        if(check_num(i, v)){
            int push = abs(n - i);
            if(ans > push){
                ans = push;
                idx = i;
            }
        }
    }

    //최소버튼수로 이동할 수 있는 번호의 길이와 최소 버튼수의 합
    return to_string(idx).size() + ans;
}

int main(){
    fastio;

    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++)
        cin >> v[i];

    if(n == 100)
        cout << 0 << endl;
    else
        cout << min(abs(n - 100), move_channel(v)) << endl;

    return 0;
}