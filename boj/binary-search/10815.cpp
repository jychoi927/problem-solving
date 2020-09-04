#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n,m;
    cin >> n;
    vector<int> cards(n);
    for(int i=0;i<n;i++)
        cin >> cards[i];
    
    cin >> m;
    vector<int> compare(m);
    for(int i=0;i<m;i++)
        cin >> compare[i];
    
    sort(cards.begin(),cards.end());
    
    for(int i=0;i<m;i++){
        long long low = 0, high = n-1;
        bool exists = false;
        //카드가 정렬되었으므로
        //비교하는 카드보다 크면 범위를 올리고
        //작으면 범위를 내리면서 탐색
        while(low <= high){
            long long mid = (low + high) / 2;
            if(compare[i] == cards[mid]){
                exists = true;
                break;
            }
            else if(compare[i] > cards[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        if(exists) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
}