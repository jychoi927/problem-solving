#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

//부분 일치 테이블
vector<int> getPartialMatch(string N){
    int m = N.size();
    vector<int> pi(m, 0);
    
    int begin = 1, matched = 0;
    //비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
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

vector<int> getPrefixSuffix(string s){
    vector<int> ret, pi = getPartialMatch(s);
    int k = s.size();
    while(k > 0){
        //s[..k-1]는 답이다.
        ret.push_back(k);
        //s[..k-1]의 접미사도 되고 접두사도 되는 문자열도 답이다.
        k = pi[k-1];
    }
    return ret;
}

int main(){
    fastio;

    string s, s1, s2;
    cin >> s1 >> s2;
    s = s1 + s2;

    vector<int> ret= getPrefixSuffix(s);
    for(int i=ret.size()-1;i>=0;i--)
        cout << ret[i] << " ";
    cout << endl;

    return 0;
}