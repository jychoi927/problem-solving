#include <iostream>
#include <cstring>

using namespace std;

bool areFriends[10][10];
bool taken[10];
int n,m;

int countPairings(){
    int firstFree = -1;
    //남은 학생들 중 가장 번호가 빠른 학생을 찾는다
    for(int i=0;i<n;i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }

    //모든 학생이 짝을 찾았으면 종료
    if(firstFree == -1)
        return 1;

    int ret = 0;
    //firstFree 번호를 가진 학생과 짝지을 학생을 찾는다
    for(int pairWith=firstFree+1;pairWith<n;pairWith++){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            //재귀 호출을 통해 나머지 짝을 전부 찾는다
            ret += countPairings();
            //다른 경우의 수를 찾기위해 짝을 초기화
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main(){
    int test_case;
    cin >> test_case;

    int x,y;
    while(test_case--){
        cin >> n >> m;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            areFriends[x][y] = true;
            areFriends[y][x] = true;
        }

        cout << countPairings() << endl;
        for(int i=0;i<10;i++){
            memset(areFriends[i], false, sizeof(bool)*10);
        }
    }
}