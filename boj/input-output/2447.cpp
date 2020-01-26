#include <iostream>

using namespace std;

void print_star(int x, int y){
    while(x != 0){
	if(x%3 == 1 && y%3 == 1){
	    cout << ' ';
	    return;
	}
	x /= 3;
	y /= 3;
    }
    cout << '*';
}

int main(){
    int n;
    cin >> n;
	
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    print_star(j,i);
	}
	cout << endl;
    }
    
    return 0;
}
