#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
	    cout << ' ';
	}
	for(int k=1;k<=i*2+1;k++){
	    cout << '*';
	}
	cout << endl;
    }

    return 0;
}
