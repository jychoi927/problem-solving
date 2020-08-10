#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 101;
int d[MAX][MAX];
string W, S;

int dp(int w, int s){
    int &ret = d[w][s];
    if (ret != -1)
        return ret;

    //와일드카드 w번째 문자와 비교문자열의 s번째 문자가 같으면 다음 문자를 비교한다.
    if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
        return ret = dp(w + 1, s + 1);

    //w와 s가 각 문자열의 사이즈에 도달하면 두 문자열이 같으므로 1을 반환한다.
    if (w == W.size() && s == S.size())
        return ret = 1;

    //*면 *에 몇글자를 대응해야할지 확인한다.
    //*에 아무 글자를 대응시키지 않거나 한 글자를 더 대응시키는 방식으로 탐색해나간다.
    if (W[w] == '*')
        if (dp(w + 1, s) || (s < S.size() && dp(w, s + 1)))
            return ret = 1;
    return ret = 0;
}

int main(){
    fastio;
    
    int _;
    cin >> _;
    while (_--){
        int n;
        cin >> W;
        cin >> n;
        vector<string> s(n);
        vector<string> ans;
        for (int i=0;i<n;i++)
            cin >> s[i];

        //각 문자열마다 와일드카드와 맞는지 확인한다.
        for (int i=0;i<n;i++){
            memset(d, -1, sizeof(d));
            S = s[i];
            if (dp(0, 0) == 1)
                ans.push_back(S);
        }

        sort(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it << endl;
    }

    return 0;
}
