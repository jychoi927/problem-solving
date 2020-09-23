#include <vector>

using namespace std;

void setZeros(vector<vector<int>>& matrix){
    vector<bool> row(matrix.size(), false);
    vector<bool> col(matrix[0].size(), false);

    //0이 있는 행과 열의 위치를 각 boolean형 배열에 기록한다.
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            if(matrix[i][j] == 0)
                row[i] = col[j] = true;

    //기록해놓은 0의 위치를 바탕으로 0이 있는 위치의 모든 행과 열을 0으로 만든다.
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            if(row[i] || col[j])
                matrix[i][j] = 0;
}