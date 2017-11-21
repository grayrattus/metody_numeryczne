#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

double func(double x) {
    return (x * x * x) - (3.0 * x * x * x) + 2.5;
}

int main() {
    double a = -10;
    double b = 10;

    double krok = 0.5;

    do {
        a += krok;
        b -= krok;
    } while (func(a) * func(b) < 0 && fabs(b) - fabs(a) <= 1);

    cout << "A:" << a;
    cout << "B:" << b;
}