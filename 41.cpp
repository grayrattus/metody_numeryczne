#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

double func(double x) {
    return (x * x * x) - (3.0 * x * x * x) + 2.5;
}

int main() {
    double a = 0;
    double b = 5;
    double dokladnosc = 0.0000005;

    double c = a;

    while ((b - a) >= dokladnosc) {
        c = (a + b) / 2;

        if (func(a) * func(c) <= 0) {
            b = c;
        } else {
            a = c;
        }
    }
        cout << "C: " << c << endl;
}