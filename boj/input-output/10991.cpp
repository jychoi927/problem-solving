#include <iostream>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
    fastio;

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
	for(int j=i;j<n-1;j++){
	    cout << ' ';
	}
	for(int k=0;k<=i;k++){
	    cout << "* ";
	}
	cout << endl;
    }
}
