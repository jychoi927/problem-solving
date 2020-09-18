#include <string>
#include <iostream>

using namespace std;

void reverse(char *str){
    char* end = str;
    char tmp;
    if(str){
        //문자열의 끝을 찾는다.
        while(*end)
            ++end;
        --end;

        //앞과 뒤의 두 문자를 바꾸고 포인터를 이동시킨다.
        //두 포인터가 중간지점에서 만날 떄 까지 반복한다.
        while(str < end){
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main(){
    char c[50] = "abcde";
    reverse(c);
    cout << c << endl;
}