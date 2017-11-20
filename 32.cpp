#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <iostream>
#include <complex>

using namespace std;

const int N = 3;

double blad(double b, double a) {
    if (a != 0) {
        return abs<double>((double)((b - a) / a));
    }
    return 999;
}

double obliczIteracje(double a[][N], double b[N], double x[N]) {
    double tempX[N];
    tempX[0] = x[0];
    tempX[1] = x[1];
    tempX[2] = x[2];
    x[0] = (double) (1.0 / a[0][0]) * (b[0] - a[0][1] * tempX[1] - a[0][2] * tempX[2]);
    x[1] = (double) (1.0 / a[1][1]) * (b[1] - a[1][0] * tempX[0] - a[1][2] * tempX[2]);
    x[2] = (double) (1.0 / a[2][2]) * (b[2] - a[2][0] * tempX[0] - a[2][1] * tempX[1]);

    return blad(x[0], tempX[0]);
}

void metodaJacobiego(double a[][N], double b[N], double x[N]) {
    double bladPrzyblizenia = 999;
    do {
        bladPrzyblizenia = obliczIteracje(a, b, x);
    } while (bladPrzyblizenia >= 0.0000005);
}

int main() {
    double a[N][N] = {
        {3.48, 1.12, -0.94},
        {1.08, 3.67, -0.87},
        {-1.21, -1.43, 4.14}
    };
    double b[N] = {
        4.158, 6.908, 9.507
    };
    double x[N] = {
        0, 0, 0
    };
    metodaJacobiego(a, b, x);

    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}
//x[0] = (1.0/a[0][0]) * (b[0] - a[0][1]*y - a[0][2]*z);
//x[1] = (1.0/a[1][1]) * (b[1] - a[1][0]*x - a[1][2]*z);
//x[2] = (1.0/a[2][2]) * (b[2] - a[2][0]*x - a[2][1]*y);