#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<n;j++){
            cout << " ";
        }
        for(int k=n-i;k<n;k++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=1;i<n;i++){
	for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int k=1;k<=n-i;k++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
