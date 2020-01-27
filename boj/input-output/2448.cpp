#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void print_star(int shift, vector<string>& s){
    int c = s.size();
    for(int i=0;i<c;i++){
	s.push_back(s[i]+s[i]);
	string tmp;
	for(int j=0;j<shift;j++)
	    tmp += "   ";
	tmp += s[i];
	for(int j=0;j<shift;j++)
	    tmp += "   ";
	s[i] = tmp;
    }
}

int main(){
    vector<string> s;
    s.push_back("  *   ");
    s.push_back(" * *  ");
    s.push_back("***** ");
	
    int n;
    cin >> n;

    int k = log(n/3) / log(2);

    for(int i=0;i<k;i++){
	print_star(int(pow(2,i)), s);
    }

    for(int i=0;i<n;i++){
	cout << s[i] << endl;
    }

    return 0;
}
