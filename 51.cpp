#include <math.h>
#include <iostream>

using namespace std;

const int PRZEDZIALY = 5;
const double A = 0.0;
const double B = 1.0;

double oblicz_funkcje(int x) {
    return pow(M_E, x) * (1 + x);
};

double blad(double a, double b, int m) {
    double dx = (b - a) / m;
    return -pow((1.0 / (12.0 * pow(m, 2))), 3) * pow(M_E, dx)*(dx + 3.0);
}

double suma_trapezow(double a, double b, int m) {
    double dx = (a + b) / m;
    double sumaWartosci = 0;
    for (int n = 1; n < m; n++) {
        sumaWartosci += oblicz_funkcje(a + n * dx);
    }
    sumaWartosci += ((oblicz_funkcje(a) + oblicz_funkcje(b)) / 2) * dx;
    return sumaWartosci;
}

int przedzialy_m(double a, double b) {
    int przedzial = 0;
    double bladPrzedzialu = blad(a, b, przedzial);
    for (przedzial; bladPrzedzialu < 0; przedzial++) {
        bladPrzedzialu = blad(a, b, przedzial);
	//cout <<bladPrzedzialu << endl;
    }
    return przedzial;
}

int main() {

    cout << "Suma trapezów wynosi: " << suma_trapezow(A, B, PRZEDZIALY) << endl;
    cout << "Błąd trapezów wynosi: " << blad(A, B, PRZEDZIALY) << endl;
    cout << "Przedział wynosi: " << przedzialy_m(A, B);

    return 0;
}