#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int d[1001];
    int r1[1001];
    int r2[1001];
    int r3[1001];
    int sum=0;
	
    cin >> n;
    for(int i=0;i<n;i++)
	cin >> d[i];

    for(int i=0;i<n;i++){
	r1[i]=1;
	for(int j=0;j<i;j++){
	    if(d[i]>d[j]){
		r1[i] = max(r1[i],r1[j]+1);
	    }
	}
    }

    for(int i=n-1;i>=0;i--){
	r2[i]=1;
	for(int j=n-1;j>i;j--){
	    if(d[i]>d[j]){
		r2[i] = max(r2[i],r2[j]+1);
	    }
	}
    }
    for(int i=0;i<n;i++){
	r3[i] = r1[i] + r2[i];
	sum = max(sum,r3[i]);
    }

    cout << sum - 1 << endl;

    return 0;
}

