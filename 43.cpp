#include <iostream>
#include<math.h>

using namespace std;

float f(float x) {
    return (x * x * x) - (3.0 * x * x * x) + 2.5;
}

void oblicz(double a, double b, double c, double dokladnosc) {
    cout << "Metoda Cieciw z dokladnoscia " <<dokladnosc << endl;
    int iteracja = 0;

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        a = b;
        b = c;
        iteracja++;
    } while (fabs(f(c)) > dokladnosc);

    cout << "Wynik: " << c << endl;
    cout << "Iteracja: " << iteracja << endl;

}

int main() {
    double a = -2;
    double b = 2;
    double dokladnosc = 0.000005;
    double c = 0;

    oblicz(a,b,c,dokladnosc);
    dokladnosc = 0.0005;
    oblicz(a,b,c,dokladnosc);
}