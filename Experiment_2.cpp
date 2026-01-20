#include <iostream>
using namespace std;

#define N 3  

// Function to input matrices
void input(int m1[N][N], int m2[N][N]) {
    cout << "Enter elements of Matrix 1 (3X3):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> m1[i][j];

    cout << "Enter elements of Matrix 2 (3X3):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> m2[i][j];
}

// Function to display matrices
void display(int m1[N][N], int m2[N][N]) {
    cout << "\nMatrix 1:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m1[i][j] << " ";
        cout << endl;
    }

    cout << "\nMatrix 2:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m2[i][j] << " ";
        cout << endl;
    }
}

// Matrix addition
void addition(int m1[N][N], int m2[N][N]) {
    int m3[N][N];
    cout << "\nAddition of matrices:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
}

// Matrix subtraction
void subtraction(int m1[N][N], int m2[N][N]) {
    int m3[N][N];
    cout << "\nSubtraction of matrices:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m3[i][j] = m1[i][j] - m2[i][j];
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
}

// Matrix multiplication
void multiplication(int m1[N][N], int m2[N][N]) {
    int m3[N][N] = {0};
    cout << "\nMultiplication of matrices:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
}

// Transpose of both matrices
void transpose(int m1[N][N], int m2[N][N]) {
    cout << "\nTranspose of Matrix 1:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m1[j][i] << " ";
        cout << endl;
    }

    cout << "\nTranspose of Matrix 2:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m2[j][i] << " ";
        cout << endl;
    }
}

// Identity matrix
void identity() {
    cout << "\nIdentity Matrix (3x3):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int m1[N][N], m2[N][N];
    int choice;

    input(m1, m2);

    do {
        cout << "\n------ MENU ------\n";
        cout << "0. Display Matrices\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Transpose\n";
        cout << "5. Identity Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0: display(m1, m2); break;
            case 1: addition(m1, m2); break;
            case 2: subtraction(m1, m2); break;
            case 3: multiplication(m1, m2); break;
            case 4: transpose(m1, m2); break;
            case 5: identity(); break;
            case 6: cout << "Exiting program..."; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 6);

    return 0;
}
