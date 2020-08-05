#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int left, int right, const vector<int>& h){
    //기저사례(판자가 하나밖에 없는 경우)
    if(left == right) return h[left];
	
    int mid = (left+right) / 2;
    //범위를 [left, mid]와 [mid+1, right]로 분할
    int ret = max(solve(left,mid, h), solve(mid+1,right, h));
    //분할된 판자에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    //가장 중간의 두 판자부터 시작
    int lo = mid, hi = mid+1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);

    //중간 두 사각형에서 왼쪽과 오른쪽으로 한칸씩 넓혀가며 사각형 전체를 덮을 때까지 진행한다.
    while(left < lo || hi < right){
        //중간 사각형의 왼쪽과 오른쪽 판자 중 높은 쪽으로 확장한다.
        if(hi < right && (lo == left || h[lo-1] < h[hi+1])){
            ++hi;
            height = min(height, h[hi]);
        }
        else {
            --lo;
            height = min(height, h[lo]);
        }
        
        ret = max(ret, height * (hi-lo+1));
    }
    return ret;
}

int main(){
    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];

        cout << solve(0,v.size()-1,v) << endl;
    }

    return 0;
}