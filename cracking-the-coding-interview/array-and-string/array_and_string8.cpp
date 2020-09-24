#include <vector>
#include <string>

using namespace std;

//kmp알고리즘에 필요한 부분일치테이블을 구한다.
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

//kmp 알고리즘으로 s2(N)가 s1+s1(H)의 부분 문자열인지를 확인한다.
bool kmp(string H, string N){
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);

    int matched = 0;
    for(int i=0;i<n;i++){
        while(matched > 0 && H[i] != N[matched])
            matched = pi[matched-1];
        if(H[i] == N[matched]){
            ++matched;
            if(matched == m){
                return true;
            }
        }
    }
    return false;
}

//s2가 s1의 회전된 문자열인지를 확인하는 방법은
//s1을 두 번 이어붙인 문자열의 부분문자열인지 확인하면 된다.
bool isRotation(string s1, string s2){
    //s1의 길이가 0 보다 크고 s2와 같을때만 s2가 회전 문자열이 될 수 있다.
    if(s1.length() == s2.length() && s1.length() > 0)
        return kmp(s1+s1, s2);
    return false;
}