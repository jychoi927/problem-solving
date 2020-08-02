#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF=9999, SWITCHES = 10, CLOCKS = 16;
//10개의 스위치
const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

//모든 시계가 12시를 가리키고 있는지 확인
bool areAligned(const vector<int>& clocks){
    for(auto it : clocks){
        if(it != 12){
            return false;
        }
    }
    return true;
}

//swtch번 스위치를 push
void push(vector<int>& clocks, int swtch){
    for(int clock=0;clock<CLOCKS;++clock){
        if(linked[swtch][clock] == 'x'){
            clocks[clock] += 3;
            if(clocks[clock] == 15)
                clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch){
    //경우의 수를 모두 탐색했을 때 모든 시계가 12시에 맞춰져있지 않다면 INF를 반환
    if(swtch == SWITCHES)
        return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    //swtch번 스위치를 0번에서 3번까지 누르는 경우를 탐색
    for(int cnt=0;cnt<4;++cnt){
        ret = min(ret, cnt+solve(clocks,swtch+1));
        push(clocks,swtch);
    }
    return ret;
}

int main(){
    int test_case;
    cin >> test_case;

    while(test_case--){
        vector<int> clock(16);
        for(int i=0;i<16;i++){
            cin >> clock[i];
        }

        int result = solve(clock,0);
        cout << (result == INF ? -1 : result) << endl;
    }
}