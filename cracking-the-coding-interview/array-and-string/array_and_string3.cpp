#include <string>
#include <algorithm>

using namespace std;

//1번 : 정렬이용
bool permutation1(string s, string t){
    if(s.length() != t.length()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

//2번 : 문자열의 문자 카운트
bool permutation2(string s, string t){
    if(s.length() != t.length()) return false;

    //Extended ASCII 코드 문자 개수 기준
    int letters[256] = {0,};
    for(char c : s)
        letters[c]++;

    for(int i=0;i<t.length();i++){
        int c = (int)t[i];
        if(--letters[c] < 0)
            return false;
    }
    
    return true;
}