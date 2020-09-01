#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

long long lan[10001];

int main(){
    fastio;

	int k, n;
    long long ans = 0, low = 1, high = 0, mid, cnt;
	cin >> k >> n;

	for(int i=1;i<=k;i++){
		cin >> lan[i];
        if(high < lan[i])
            high = lan[i];
	}

    //길이 1부터 가장 긴 랜선 길이만큼 이분 탐색
	while(low <= high){
        mid = (low + high) / 2;
		cnt = 0;
        //랜선을 mid 길이만큼 잘랐을 때의 개수
		for(int i=1;i<=k;i++)
			cnt += lan[i] / mid;
		
        //랜선이 필요 개수 n개를 넘는 경우
        //더 최댓값이 있을 수 있으므로 low를 높여서 다시 탐색
		if(cnt >= n){
            if(mid > ans)
                ans = mid;
			low = mid + 1;
		}
        //랜선이 n개가 넘지 못하면 길이를 줄여서 다시 탐색
        else
            high = mid - 1;
	}
    
    cout << ans << endl;

	return 0;
}