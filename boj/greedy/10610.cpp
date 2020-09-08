#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
	fastio;

	string s;
	cin >> s;

	vector<int> v;
	bool flag = false;
	int sum = 0;
    for(int i=0;i<s.length();i++){
		int tmp = s[i] - '0';
		v.push_back(tmp);
		sum += tmp;
		if(tmp == 0)
			flag = true;
	}

    //s에 0이 없거나 s의 각 문자를 더한 값이 3으로 나누어지지 않으면
    //해당 수를 구할 수 없다.
	if(!flag || sum % 3 != 0)
		cout << -1 << endl;
	else{
        sort(v.begin(), v.end(), greater<int>());
	    for(int i=0;i<s.length();i++)
		    cout << v[i];
        cout << endl;
    }

	return 0;
}