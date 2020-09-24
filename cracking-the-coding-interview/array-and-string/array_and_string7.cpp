#include <vector>

using namespace std;

//1번 : bit 벡터 사용
void setZeros(vector<vector<int>>& matrix){
	int row = 0, col = 0;

    //0이 있는 행과 열의 위치를 bit로 기록한다.
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            if(matrix[i][j] == 0){
				row |= (1 << i);
				col |= (1 << j);
			}

    //기록해놓은 0의 위치를 바탕으로 0이 있는 위치의 모든 행과 열을 0으로 만든다.
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            if((row & (1 << i)) || (col & (1 << j)))
                matrix[i][j] = 0;
}

//2번 : boolean 변수 두 개와 기존 행렬만 사용
void nullifyRow(vector<vector<int>>& matrix, int row){
	for(int j=0;j<matrix[0].size();j++)
		matrix[row][j] = 0;
}

void nullifyCol(vector<vector<int>>& matrix, int col){
	for(int i=0;i<matrix.size();i++)
		matrix[i][col] = 0;
}

void setZeros2(vector<vector<int>>& matrix){
	int n = matrix.size(), m = matrix[0].size();
	bool rowHasZero = false;
	bool colHasZero = false;

	//첫 번째 행에 0이 있는지 확인한다.
	for(int j=0;j<m;j++){
		if(matrix[0][j] == 0){
			rowHasZero = true;
			break;
		}
	}

	//첫 번째 열에 0이 있는지 확인한다.
	for(int i=0;i<n;i++){
		if(matrix[i][0] == 0){
			colHasZero = true;
			break;
		}
	}

	//나머지 행렬에 0을 확인하고
	//0이 있는 행의 첫 번째 열과
	//0이 있는 열의 첫 번째 행을 0으로 바꿔준다.
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	//첫 번째 열에서 0이 들어간 행을 전부 0으로 바꿔준다.
	for(int i=1;i<n;i++)
		if(matrix[i][0] == 0)
			nullifyRow(matrix, i);
	
	//첫 번째 행에서 0이 들어간 열을 전부 0으로 바꿔준다.
	for(int j=1;j<m;j++)
		if(matrix[0][j] == 0)
			nullifyCol(matrix, j);
	
	//첫 번째 행과 열에 0이 들어가 있는 경우 0으로 바꿔준다.
	if(rowHasZero) nullifyRow(matrix, 0);
	if(colHasZero) nullifyCol(matrix, 0);
}