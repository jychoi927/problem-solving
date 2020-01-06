#include <iostream>

using namespace std;

int main(){
    int a,b,test_case;
    cin >> test_case;

    for(int i=1;i<=test_case;i++){
        cin >> a >> b;
	printf("Case #%d: %d\n",i,a+b);
    }
}
