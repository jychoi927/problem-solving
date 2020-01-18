#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int *arr = new int[n];
	
    for(int i=0;i<n;i++){
	cin >> arr[i];
    }
    
    cout << *min_element(arr,arr+n) << " " << *max_element(arr,arr+n) << endl;
    
    return 0;

}
