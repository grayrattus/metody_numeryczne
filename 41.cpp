#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    double a = 2;
    double b = 1;
    double p_przedzialu = -10;
    double k_przedzialu = 10;
    double dokladnosc = 0.000005;

    do {
        double x = (p_przedzialu + k_przedzialu) / 2;
        double y = a * x + b;

        if (y == 0) {
            cout << "X: " << x;
        } else if (a * y < 0) {
	    p_przedzialu = x;
	    a = y;
        } else {
	    k_przedzialu = x;
	    b = y;
	}
    } while (fabs(k_przedzialu - p_przedzialu) > dokladnosc);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p_przedzialu: " << p_przedzialu << endl;
    cout << "k_przedzialu: " << k_przedzialu << endl;

}