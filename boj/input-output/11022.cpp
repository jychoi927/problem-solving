#include <iostream>

using namespace std;

int main(){
    int test_case,a,b;
    cin >> test_case;

    for(int i=1;i<=test_case;i++){
	cin >> a >> b;
	printf("Case #%d: %d + %d = %d\n",i,a,b,a+b);
    }

    return 0;
}
