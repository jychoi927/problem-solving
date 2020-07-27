#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct point{
    double y,x;
};

//도형1,2
vector<point> hull1, hull2;
//도형1,2의 위 껍질과 아래 껍질
vector<pair<point,point>> upper, lower;

//주어진 다각형을 위 껍질과 아래 껍질로 분해
void decompose(const vector<point>& hull){
    int n = hull.size();

    for(int i=0;i<n;i++){
        if(hull[i].x < hull[(i+1)%n].x)
            lower.push_back(make_pair(hull[i], hull[(i+1)%n]));
        else
            upper.push_back(make_pair(hull[i], hull[(i+1)%n]));
    }
}

//x가 선분[a,b]구간 안에 포함되는지 확인
bool between(const point& a, const point& b, double x){
    return (a.x <= x && x <= b.x || b.x <= x && x <= a.x);
}

선분 (a,b)와 주어진 위치의 수직선이 교차하는 위치를 반환
double at(const point& a, const point& b, double x){
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return a.y + dy * (x - a.x) / dx;
}

//두 다각형의 교집합을 수직선으로 잘랐을 때 단면의 길이를 반환
double vertical(double x){
    double minUp = 1e20, maxLow = -1e20;
    //위 껍질의 선분을 순회하며 최소 y좌표를 찾는다
    for(int i=0;i<upper.size();i++){
        if(between(upper[i].first, upper[i].second, x)){
            minUp = min(minUp, at(upper[i].first, upper[i].second, x));
        }
    }
    //아래 껍질의 선분을 순회하며 최대 y좌표를 찾는다.
    for(int i=0;i<lower.size();i++){
        if(between(lower[i].first, lower[i].second, x)){
            maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
        }
    }

    return minUp - maxLow;
}

//다각형에서 가장 작은 x값 반환
double minX(const vector<point>& a){
    double m = 101;
    for(int i=0;i<a.size();i++){
        m = min(m, a[i].x);
    }
    return m;
}

//다각형에서 가장 큰 x값 반환
double maxX(const vector<point>& a){
    double m = -101;
    for(int i=0;i<a.size();i++){
        m = max(m, a[i].x);
    }
    return m;
}

//삼분검색
double solve(){
    double low = max(minX(hull1), minX(hull2));
    double high = min(maxX(hull1), maxX(hull2));

    //예외처리(두 다각형이 겹치지 않는 경우)
    if(low > high)
        return 0;

    for(int i=0;i<100;i++){
        double aab = (low*2 + high) / 3.0;
        double abb = (low + high*2) / 3.0;

        if(vertical(aab) < vertical(abb))
            low = aab;
        else
            high = abb;
        }

    return max(0.0, vertical(high));
}


int main(){
    int test_case;
    cin >> test_case;
  
    while(test_case--){
        int n, m;
        cin >> n >> m;

        hull1.clear();
        hull1.resize(n);
        hull2.clear();
        hull2.resize(m);

        for(int i=0;i<n;i++){
            cin >> hull1[i].x >> hull1[i].y;
        }
        for(int i=0;i<m;i++){
            cin >> hull2[i].x >> hull2[i].y;
        }

        upper.clear();
        lower.clear();
        decompose(hull1);
        decompose(hull2);

        double result = solve();
        if(result <= 0)
            cout << "0.000000" << endl;
        else
            printf("%.10lf\n",result);
    }
}