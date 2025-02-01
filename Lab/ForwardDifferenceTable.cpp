#include<bits/stdc++.h>
using namespace std;
void forwardDifferenceTable(double x[], double y[], int n) {
    double diffTable[n][n];

    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
    cout << "\nForward Difference Table:\n";
    cout << setw(10) << "x" << setw(10) << "y";
    for (int j = 1; j < n; j++) {
        cout << setw(10) << "Δ^" << j << "y";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; j++) {
            cout << setw(10) << diffTable[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter values of x and y:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    forwardDifferenceTable(x, y, n);

    return 0;
}
