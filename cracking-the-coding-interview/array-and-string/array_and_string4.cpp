#include <string>

using namespace std;

//1번 : char 배열 사용
void replaceSpaces1(char str[], int length){
    int spaceCount = 0, newLength;
    for(int i=0;i<length;i++)
        if(str[i] == ' ')
            spaceCount++;
    
    newLength = length + spaceCount * 2;
    str[newLength] = '\0';

    for(int i=length-1;i>=0;i--){
        if(str[i] == ' '){
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;
        }
        else
            str[--newLength] = str[i];
    }
}

//2번 : string 사용
string replaceSpaces2(string s){
    string ret = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ')
            ret += "%20";
        else
            ret += s[i];
    }
    return ret;
}