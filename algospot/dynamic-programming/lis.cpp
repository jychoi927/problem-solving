#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 500;
int a[MAX];
int C[MAX];
int n;
int idx;

void go(int num){
    //C에 아무 값도 없거나 C의 마지막 값이 num보다 작으면 num을 C에 추가해준다.
    if (idx == 0 || (idx > 0 && C[idx - 1] < num)){
        C[idx++] = num;
        return;
    }

    int front = 0, rear = idx-1;
    //이분 탐색으로 C에서 num보다 작은 가장 큰 값의 위치를 찾는다.
    while (front <= rear){
        int mid = (front+rear) / 2;
        if (C[mid] < num)
            front = mid+1;
        else
            rear = mid-1;
    }
    //num보다 작은 가장 큰 값의 오른쪽 값을 num으로 교체한다.
    C[rear+1] = num;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=0;i<n;i++)
            cin >> a[i];

        idx = 0;
        for (int i=0;i<n;i++)
            go(a[i]);

        cout << idx << endl;
    }

    return 0;
}
