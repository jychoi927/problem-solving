#include <iostream>

using namespace std;

char Map[500][500];

void draw_stars(int depth, int idx){
    if(depth == 1){
        Map[idx][idx] = '*';
        Map[idx+1][idx] = '*';
        Map[idx+2][idx] = '*';
        return;
    }
	
    int len = 4 * (depth - 1) + 1;
	
    for(int i=idx;i<len+idx;i++){
        Map[idx][i] = '*';
        Map[idx + len + 1][i] = '*';
    }
	
    for(int i=idx;i<len+idx+2;i++){
        Map[i][idx] = '*';
        Map[i][idx + len - 1] = '*';
    }
	
    Map[idx+1][idx+len-1] = ' ';
    Map[idx+2][idx+len-2] = '*';
	
    draw_stars(depth-1, idx+2);
    return;
}

int main(){
    int n;
    cin >> n;
	
    if(n == 1){
        cout << '*' << endl;
        return 0;
    }
	
    int len = 4 * (n - 1) + 1;
	
    for(int i=0;i<len+2;i++)
        for(int j=0;j<len;j++)
            Map[i][j] = ' ';
		
    draw_stars(n,0);
	
    for(int i=0;i<len+2;i++){
        if(i == 1){
            cout << '*' << endl;
            continue;
        } 
        for(int j=0;j<len;j++){
            cout << Map[i][j];
        }
        cout << endl;
    }
	
    return 0;
}