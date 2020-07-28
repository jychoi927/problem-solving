#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

//천만까지 가장 작은 소인수를 미리 minFactor에 계산
const int MAX = 10000001;
int minFactor[MAX];
//i의 소인수 분해에 들어가는 minFactor[i]의 개수
int minFactorPower[MAX];
int factors[MAX];

void getFactorSmart(){
    factors[1] = 1;
    for(int n=2;n<=MAX;++n){
        //소수인 경우 약수가 2개밖에 없다
        if(minFactor[n] == n){
            minFactorPower[n] = 1;
            factors[n] = 2;
        }
        //소수가 아닌 경우
        else{
            //n을 n의 가장 작은 소인수로 나눈다
            int p = minFactor[n];
            int m = n / p;

            //n과 m의 가장 작은 소인수가 서로 다른 경우에는 n의 소인수에 p가 1개만 존재한다
            if(p != minFactor[m])
                minFactorPower[n] = 1;
            //n과 m의 가장 작은 소인수가 서로 같은 경우에는 
            //n의 소인수에 m의 가장 작은 소인수의 개수 + 1개가 존재한다
            else
                minFactorPower[n] = minFactorPower[m] + 1;

            int a = minFactorPower[n];
            factors[n] = (factors[m] / a) * (a + 1);
        }
    }
}

//에라토스테네스의 체를 사용하여 각 수의 가장 작은 소인수 구하기
void eratosthenes(){
    //1은 예외처리한다
    minFactor[0] = minFactor[1] = 1;

    for(int i=2;i<=MAX;i++){
        minFactor[i] = i;
    }

    int sqrtn = int(sqrt(MAX));
    for(int i=2;i<=sqrtn;i++){
        if(minFactor[i] == i){
            for(int j=i*i;j<=MAX;j+=i){
                if(minFactor[j] == j)
                    minFactor[j] = i;
            }
        }
    }
}

int main(){
    int test_case;
    int n,low,high;
    cin >> test_case;

    eratosthenes();
    getFactorSmart();
    while(test_case--){
        int count = 0;
        cin >> n >> low >> high;
        for(int i=low;i<=high;i++){
            if(n == factors[i]){
                count++;
            }
        }

        cout << count << endl;
    }
}