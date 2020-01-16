#include <iostream>

using namespace std;

int month[12] = {0,31,28,31,30,31,30,31,31,30,31,30};

int main(){
    int mon, day;
    cin >> mon >> day;

    int day_sum=0;
    int result;

    for(int i=1;i<mon;i++){
	day_sum+=month[i];
    }
	
    day_sum+=day;
    result = day_sum % 7;

    switch(result){
        case 0:
	    cout << "SUN";
	    break;
	case 1:
	    cout << "MON";
	    break;
	case 2:
	    cout << "TUE";
	    break;
	case 3:
	    cout << "WED";
	    break;
	case 4:
	    cout << "THU";
	    break;
	case 5:
	    cout << "FRI";
	    break;
	case 6:
	    cout << "SAT";
	    break;
	default:
	    cout << "ERROR";
	    break;
    }
    cout << endl;
    
    return 0;

}
