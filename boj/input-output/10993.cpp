#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1024;
char Map[MAX][MAX * 2];

void draw_stars(int depth, int x, int y){
    if (depth == 1){
        Map[y][x] = '*';
        return;
    }

    int row = pow(2, depth + 1) - 3;
    int col = pow(2, depth) - 1;

    //depth가 짝수일 때는 밑을 향한 삼각형을 만든다.
    if (depth % 2 == 0){
        //삼각형의 가장 윗부분을 만든다.
        for (int i = x; i < row + x; i++){
            Map[y][i] = '*';
        }
        //위에서 밑으로 내려가며 만든다.
        for (int i = 1; i < col; i++){
            Map[y + i][x + i] = '*';
            Map[y + i][x + row - i - 1] = '*';
        }

        draw_stars(depth - 1, pow(2, depth - 1) + x, y + 1);
    }
    //depth가 홀수일 때는 위를 향한 삼각형을 만든다.
    else{
        //삼각형의 가장 밑부분을 만든다.
        for (int i = x; i < row + x; i++){
            Map[y + col - 1][i] = '*';
        }
        //밑에서 위로 올라가며 만든다.
        for (int i = 0; i < col; i++){
            Map[y + i][x + row / 2 - i] = '*';
            Map[y + i][x + row / 2 + i] = '*';
        }

        draw_stars(depth - 1, pow(2, depth - 1) + x, col / 2 + y);
    }

    return;
}

int main(){
    int n;
    cin >> n;

    if (n == 1){
        cout << '*' << endl;
        return 0;
    }

    int row = pow(2, n + 1) - 3;
    int col = pow(2, n) - 1;

    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            Map[i][j] = ' ';

    draw_stars(n, 0, 0);

    //각 라인마다 마지막 별표가 오는지점까지만 출력해야한다.
    if (n % 2 == 0){
        for (int i = 0; i < col; i++){
            for (int j = 0; j < row - i; j++){
                cout << Map[i][j];
            }
            cout << endl;
        }
    }
    else{
        for (int i = 0; i < col; i++){
            for (int j = 0; j < row - col + i + 1; j++){
                cout << Map[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}