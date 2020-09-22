#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix, int n){
    //가장 바깥쪽 레이어부터 안쪽 레이어까지 반복한다.
    for(int layer=0;layer<n/2;++layer){
        int first = layer;
        int last = n - 1 - layer;
        //현재 레이어의 모서리부터 회전하고 한칸씩 이동한다.
        for(int i=first;i<last;++i){
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];            //왼쪽 아래 -> 왼쪽 위
            matrix[last - offset][first] = matrix[last][last - offset]; //오른쪽 아래 -> 왼쪽 아래
            matrix[last][last - offset] = matrix[i][last];              //오른쪽 위 -> 왼쪽 아래
            matrix[i][last] = top;                                      //왼쪽 위 -> 오른쪽 위
        }
    }
}