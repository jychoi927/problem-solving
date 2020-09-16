#include <string>
#include <algorithm>

using namespace std;

//1번
bool isUniqueChar1(string str){
    //Standard ASCII 기준 128가지의 문자가 있기 때문에
    //문자열의 길이가 128을 넘으면 중복된 문자열이 존재하게된다.
    if(str.length() > 128) return false;
    
    bool char_set[128];
    for(int i=0;i<str.length();i++){
        int val = str[i];
        if(char_set[val])
            return false;
        char_set[val] = true; 
    }
    return true;
}

//2번
bool isUniqueChar2(string str){
    if(str.length() > 26) return false;
    
    int checker = 0;
    for(int i=0;i<str.length();i++){
        int val = str[i] - 'a';
        //1번 방법에서 boolean형 배열에 표시하는 것처럼
        //해당 알파벳이 존재하는지를 int형 변수에 비트로 표시한다.
        if((checker & (1 << val)) > 0)
            return false;
        checker |= (1 << val);
    }
    return true;
}

//3번
bool isUniqueChar3(string str){
    if(str.length() > 128) return false;
    
    //서로 다른 모든 문자를 비교한다.
    for(int i=0;i<str.length();i++)
        for(int j=i+1;j<str.length();j++)
            if(str[i] == str[j])
                return false;

    return true;
}

//4번
bool isUniqueChar4(string str){
    if(str.length() > 128) return false;
    
    //문자열 정렬 후 인접한 두 문자를 비교한다.
    sort(str.begin(), str.end());
    for(int i=1;i<str.length();i++)
        if(str[i-1] == str[i])
            return false;

    return true;
}