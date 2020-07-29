#include <iostream>
#include <vector>

using namespace std;

//최대공약수를 구하기 위한 유클리드 알고리즘
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

//분수 a/b보다 같거나 크 최소의 자연수 반환
int ceil(int a, int b){
    return (a+b-1) / b;
}

vector<int> solve(const vector<int>& recipe, const vector<int> put){
    int n = recipe.size();
    int b = recipe[0];
    for(int i=1;i<n;i++)
        b = gcd(b,recipe[i]);

    int a = b;
    // 1/b씩 더하는 분수연산 대신
    // ceil(put[i]*b / recipe[i])의 최대값을 구한다
    for(int i=0;i<n;i++)
        a = max(a, ceil(put[i]*b, recipe[i]));
	
    vector<int> ret(n);
    // a/b배 재료를 레시피에 곱하고 이미 넣은 재료만큼 빼주면 
    // 비율에 맞는 필요한 최소 재료양이 된다 
    for(int i=0;i<n;i++)
        ret[i] = recipe[i] * a / b - put[i];
    return ret;
}

int main(){
    int test_case, n;
    cin >> test_case;
    vector<int> recipe, put, result;

    while(test_case--){
        cin >> n;
        recipe.clear();
        put.clear();
        recipe.resize(n);
        put.resize(n);

        for(int i=0;i<n;i++)
            cin >> recipe[i];
        for(int i=0;i<n;i++)
            cin >> put[i];

        result = solve(recipe, put);
        for(auto it : result)
            cout << it << " ";
        cout << endl;
    }
}