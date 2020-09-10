#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n, begin, end;
    vector<pair<int, int>> meetings;

    cin >> n;
    //회의가 끝나는 시간을 기준으로 정렬한다.
    for(int i=0;i<n;i++){
        cin >> begin >> end;
        meetings.push_back(make_pair(end, begin));
    }
    sort(meetings.begin(), meetings.end());

    int prev_end = 0, ans = 0;
    for(int i=0;i<meetings.size();i++){
        begin = meetings[i].second;
        end = meetings[i].first;

        //회의 시작시간이 이전 회의가 끝난 시간 이상이면
        //해당 회의를 선택해준다.
        if(prev_end <= begin){
            prev_end = end;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}