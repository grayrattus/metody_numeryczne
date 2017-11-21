#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

double func(double x) {
    return (x * x * x) - (3.0 * x * x * x) + 2.5;
}

void oblicz(double a, double b, double dokladnosc) {
    cout << "Metoda Połowienia z dokladnoscia " <<dokladnosc << endl;
    int iteracja = 0;

    double c = a;

    while ((b - a) >= dokladnosc) {
        c = (a + b) / 2;

        if (func(a) * func(c) <= 0) {
            b = c;
        } else {
            a = c;
        }
        iteracja++;
    }
    cout << "Wynik: " << c << endl;
    cout << "Iteracja: " << iteracja << endl;

}

int main() {
    double a = 0;
    double b = 5;
    double dokladnosc = 0.000005;

    oblicz(a,b,dokladnosc);
    dokladnosc = 0.0005;
    oblicz(a,b,dokladnosc);
}