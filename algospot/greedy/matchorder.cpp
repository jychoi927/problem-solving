#include <iostream>
#include <set>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int russian[100];
int korean[100];
int n;

int order(){
    int wins = 0;
    //한국 선수를 오름차순으로 정렬시킨다.
    multiset<int> ratings(korean, korean+n);
    for(int rus=0;rus<n;++rus){
        //가장 레이팅이 높은 한국 선수가 이길 수 없는 경우
        //가장 레이팅이 낮은 한국 선수를 매칭시킨다.
        if(*ratings.rbegin() < russian[rus])
            ratings.erase(ratings.begin());
        //해당 러시아 선수를 이길 수 있는 선수 중 가장 레이팅이 낮은 선수를 매칭시킨다.
        else{
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }
    return wins;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while(_--){
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> russian[i];
        for(int i=0;i<n;i++)
            cin >> korean[i];

        cout << order() << endl;
    }

    return 0;
}