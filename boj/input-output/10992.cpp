#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n;
    cin >> n;

    for(int i=0;i<n-1;i++){
	for(int j=i;j<n-1;j++){
	    cout << ' ';
	}
	cout << '*';

	if(i==0){
	    cout << endl;
	    continue;
	}

	for(int k=0;k<i*2-1;k++){
	    cout << ' ';
	}
	cout << '*' << endl;
		
    }

    for(int i=0;i<n*2-1;i++){
	cout << '*';
    }
    cout << endl;

    return 0;
}
