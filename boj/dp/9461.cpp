#include <iostream>

using namespace std;

int main(){
    int test_case, n;
	
    long long int d[101] = {0,1,1,1,2,2,3,4,5,7,9};
    for(int i=11;i<=100;i++){
	d[i] = d[i-1] + d[i-5];
    }

    cin >> test_case;
    while(test_case--){
	cin >> n;
	cout << d[n] << endl;
    }

    return 0;
}
