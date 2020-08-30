#include <iostream>
#include <vector>
#include <string>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

vector<int> getPartialMatch(string N){
    int m = N.size();
    vector<int> pi(m, 0);
    
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0)
                ++begin;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int kmp(string H, string N){
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);

    int matched = 0;
    for(int i=0;i<n;i++){
        while(matched > 0 && H[i] != N[matched])
            matched = pi[matched-1];
        if(H[i] == N[matched]){
            ++matched;
            //모든 글자가 매치된 경우 처음 시작점(이동 수)을 반환한다.
            if(matched == m){
                return i-m+1;
            }
        }
    }
    //모든 경우가 무조건 타겟으로 가기 때문에 해당 반환값은 신경쓸 필요가 없다.
    return -1;
}

int shift(string original, string target){
    return kmp(original+original, target);
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        vector<string> s(n+1);
        for(int i=0;i<=n;i++)
            cin >> s[i];
        
        int ans = 0;
        //반시계방향 = original+original, target
        //시계방향 = target+target, original
        for(int i=0;i<n;i++){
            if(i%2 == 1)
                ans += shift(s[i], s[i+1]);
            else
                ans += shift(s[i+1], s[i]);
        }

        cout << ans << endl;
    }

    return 0;
}