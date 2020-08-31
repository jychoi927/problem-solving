#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

struct Comparator{
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t)
    {
    }
    bool operator()(int a, int b){
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};

//접미사 배열을 계산하는 맨버-마이어스 알고리즘
vector<int> getSuffixArray(const string& s){
    int n = s.size();
    int t = 1;
    vector<int> group(n+1);
    for(int i=0;i<n;++i)
        group[i] = s[i];
    group[n] = -1;

    vector<int> perm(n);
    for(int i=0;i<n;i++)
        perm[i] = i;

    while(t < n){
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);

        t *= 2;
        if(t >= n) break;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for(int i=1;i<n;++i){
            if(compareUsing2T(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
    }
    return perm;
}

//s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int i, int j){
    int k = 0;
    while(i < s.size() && j < s.size() && s[i] == s[j]){
        ++i; ++j; ++k;
    }
    return k;
}

//k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다.
int longestPrefix(int k, const string& s){
    vector<int> a = getSuffixArray(s);
    int ret = 0;
    for(int i=0;i+k<=s.size();++i)
        ret = max(ret, commonPrefix(s, a[i], a[i+k-1]));
    return ret;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        int k;
        string s;
        cin >> k >> s;
        cout << longestPrefix(k, s) << endl;
    }

    return 0;
}