#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=n-i;j<n;j++){
            cout << "*";
        }
        for(int k=1;k<=n*2-i*2;k++){
            cout << " ";
        }
	for(int l=n-i;l<n;l++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=1;i<n;i++){
	for(int j=i;j<n;j++){
            cout << "*";
        }
        for(int k=1;k<=i*2;k++){
            cout << " ";
        }
	for(int l=i;l<n;l++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
