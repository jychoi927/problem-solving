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

int maxOverlap(string a, string b){
    int n = a.size(), m = b.size();
    vector<int> pi = getPartialMatch(b);

    int begin = 0, matched = 0;
    while(begin < n){
        if(matched < m && a[begin + matched] == b[matched]){
            ++matched;
            //a의 마지막 문자까지 탐색을 마친 경우
            //현재까지 a와 b의 겹치는 부분의 길이를 반환한다.
            if(begin + matched == n)
                return matched;
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
    return 0;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        string s, h;
        cin >> s;

        for(int i=s.size()-1;i>=0;i--)
            h += s[i];
        //두 문자열에서 겹치는 부분의 길이를 maxOverlap에서 반환하므로
        //두 문자열의 길이에서 겹치는 부분을 빼준다.
        cout << s.length() * 2 - maxOverlap(s,h) << endl;
    }

    return 0;
}