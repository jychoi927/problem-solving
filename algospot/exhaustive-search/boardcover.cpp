#include <iostream>
#include <vector>
#include <string>

using namespace std;

//게임판을 채울 수 있는 도형의 네 가지 모습
int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};

//게임판의 x,y 위치에서
//delta가 1이면 게임판을 type번 도형 모습으로 덮는다
//delta가 -1이면 게임판의 type번 도형을 없앤다
bool set(vector<vector<int>>& board, int y, int x, int type, int delta){
    bool ok = true;
    for(int i=0;i<3;i++){
        //x,y를 기준으로 type번째 도형의 모습
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];
        //도형이 게임판 밖으로 나가거나 다른 도형과 겹치는지 확인
        if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        //delta가 -1인 경우
        else if((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>>& board){
    int y = -1;
    int x = -1;
    //도형의 맨 윗줄 왼쪽을 기준으로 가장 먼저 보이는 흰칸을 찾는다
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }

    //모든 칸을 채운 경우
    if(y == -1) return 1;
    int ret = 0;
    for(int type=0;type<4;++type){
        //board(y,x)를 type번 도형으로 덮을 수 있으면 재귀 호출
        if(set(board,y,x,type,1))
            ret += cover(board);
        //덮었던 블록을 치운다
        set(board,y,x,type,-1);
    }
    return ret;
}

int main(){
    int test_case;
    cin >> test_case;

    int y,x;
    while(test_case--){
        cin >> y >> x;
        vector<vector<int>> board(y,vector<int>(x,0));
        string tmp;

        for(int i=0;i<y;i++){
            cin >> tmp;
            for(int j=0;j<tmp.size();j++){
                if(tmp[j] == '#')
                    board[i][j] = 1;
            }
        }

        cout << cover(board) << endl;

    }
}