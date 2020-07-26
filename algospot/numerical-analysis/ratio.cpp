#include <iostream>

using namespace std;

//주어진 최대 게임수
long long MAX = 2000000000;

//플레이한 게임 횟수 b에서 a번 승리했을 때의 승률
int ratio(long long b, long long a){
    return (a * 100) / b;
}

//이분법
int neededGames(long long games, long long won){
    //현재 승률과 최대 게임수만큼 플레이 했을 때의 승률이 같으면
    //즉, 20억번 연속으로 승리를 해도 1%가 오르지 않았기 때문에 -1을 반환
    if(ratio(games,won) == ratio(games+MAX,won+MAX))
        return -1;

    long long low = 0, high = MAX;

    while(low+1 < high){
        long long mid = (low + high) / 2;

        //mid번 게임을 연속으로 승리를 해도 승률이 오르지 않는다면 low를 mid로 올려줍니다
        if(ratio(games, won) == ratio(games+mid, won+mid))
            low = mid;
        //승률이 올랐다면 high를 mid로 낮춰줍니다
        else
            high = mid;
    }

    return high;
}

int main(){
    int test_case;
    long long n,m;
    
    cin >> test_case;
    
    while(test_case--){
        cin >> n >> m;
        cout << neededGames(n,m) << endl;
    }
}