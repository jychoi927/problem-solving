#include <iostream>
#include <algorithm>

using namespace std;

long long a[101][101];
long long ans = -1;

int main(){
	int n, m;
    scanf("%d%d", &n, &m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1lld", &a[i][j]);
            //부분합을 구해준다.
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    //세로 혹은 가로로만 나누는 경우를 제외하고
    //큰 직사각형에서 나올 수 있는 작은 세 가지 직사각형들의 값을 구한다.
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            ans = max(ans, a[i][j] * (a[n][j] - a[i][j]) * (a[n][m] - a[n][j]));
            ans = max(ans, a[n][j] * (a[i][m] - a[i][j]) * (a[n][m] - a[n][j] - a[i][m] + a[i][j]));
            ans = max(ans, a[i][m] * (a[n][j] - a[i][j]) * (a[n][m] - a[n][j] - a[i][m] + a[i][j]));
            ans = max(ans, a[i][j] * (a[i][m] - a[i][j]) * (a[n][m] - a[i][m]));
        }
    }

    //세로로 삼등분한 값을 구한다.
    for(int i=1;i<=m-2;i++)
        for(int j=i+1;j<=m-1;j++)
            ans = max(ans, a[n][i] * (a[n][j] - a[n][i]) * (a[n][m] - a[n][j]));

    //가로로 삼등분한 값을 구한다.
    for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++)
            ans = max(ans, a[i][m] * (a[j][m] - a[i][m]) * (a[n][m] - a[j][m]));

    printf("%lld\n", ans);

    return 0;
}