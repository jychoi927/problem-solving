#include <string>

using namespace std;

//1번 : string 사용
string compressBetter1(string str){
    string mystr;
    
    char last = str[0];
    int count = 1;
    for(int i=1;i<str.length();i++){
        //반복되는 문자만큼 카운트 증가시킨다.
        if(str[i] == last)
            count++;
        //반복이 끝났으면 해당 문자를 압축형태로 추가해준다.
        else{
            mystr.append(last + to_string(count));
            last = str[i];
            count = 1;
        }
    }

    //위 반복문에서 마지막 문자에 대해서는 처리되지 않았기 때문에
    //마지막 문자를 압축형태로 추가해준다.
    mystr.append(last + to_string(count));

    if(mystr.length() >= str.length())
        return str;
    else
        return mystr;
}

//2번 : char 배열 사용
int setChar(char array[], char c, int index, int count){
    array[index++] = c;
    for(char x : to_string(count))
        array[index++] = x;
    return index;
}

string compressBetter2(string str){
    char *array = new char[str.length()];
    char last = str[0];
    int count = 1, index = 0;
    for(int i=1;i<str.length();i++){
        if(str[i] == last)
            count++;
        else{
            index = setChar(array, last, index, count);
            last = str[i];
            count = 1;
        }
    }

    index = setChar(array, last, index, count);
    return string(array);
}