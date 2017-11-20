#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <math.h>

const int PRZEDZIALY = 5 * 2;
const double A = 0.0;
const double B = 1.0;

using namespace std;
double oblicz_funkcje(int x) {
    return pow(M_E, x) * (1 + x);
};

int main() {
    const int PRZEDZIALY = 5; 
    double calka = 0, st = 0, x;
    double dx = (B - A) / PRZEDZIALY;

    calka = 0;
    st = 0;
    for (int i = 1; i < PRZEDZIALY; i++) {
        x = A + i * dx;
        st += oblicz_funkcje(x - dx / 2);
    }
    calka += oblicz_funkcje(x);
    calka = dx / 6 * (oblicz_funkcje(A) + oblicz_funkcje(B) + 2 * calka + 4 * st);
    cout << "Całka wynosi : " << calka << endl ;
    return 0;
} 