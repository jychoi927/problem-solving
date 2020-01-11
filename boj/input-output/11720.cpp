#include <iostream>

using namespace std;

int main(){
    int n,num;
    int sum=0;

    cin >> n;
    
    while(n--){
        scanf("%1d",&num);
	sum += num;
    }
    cout << sum << endl;
}

