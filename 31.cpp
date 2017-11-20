#include <iostream>

using namespace std;

const int N = 3;

void wyswietl_macierze(double a[][N], double b[N]) {
    for (int wiersz = 0; wiersz < N; wiersz++) {
        for (int kolumny = 0; kolumny < N; kolumny++) {
            cout << a[wiersz][kolumny] << "\t";
        }
        cout << "\t | \t" << b[wiersz] << "\t";
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void eliminuj_do_1(double a[][N], double b[N], int pozycja) {
    double tempDiv = a[pozycja][pozycja];
    for (int i = pozycja; i < N; i++) {
        a[pozycja][i] /= tempDiv;
    }
    b[pozycja] /= tempDiv;
}

void eliminacja_przednia(double a[][N], double b[N]) {
    for (int i = 0; i < N; i++) {
        eliminuj_do_1(a, b, i);
        for (int j = i + 1; j < N; j++) {
            double tempSub = a[j][i];
            for (int k = i; k < N; k++) {
                a[j][k] -= tempSub * a[i][k];
            }
            b[j] -= tempSub * b[i];
        }
        cout << "krok: " << i << endl;
        wyswietl_macierze(a, b);
    }
}

void eliminacja_wsteczna(double a[][N], double b[N], double x[N]) {
    x[N - 1] = b[N - 1] / a[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++) {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
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
    double x[N] = {0};

    //wyswietl_macierze(a, b);
    eliminacja_przednia(a, b);
    //wyswietl_macierze(a, b);
    eliminacja_wsteczna(a, b, x);
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}