//Using snake_case! Using camelCase for class!
#include<iostream>
#include<Windows.h>

using namespace std;

void two_dimensional_array() {
    HANDLE matrix_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(matrix_color, 0x0a);
    int number_matrices;
    while (true) {
        cout << "enter the number of matrices: \n";
        if (!(cin >> number_matrices)) {
            cin.clear();
            cin.ignore();
            cout << "error\n";
            continue;
        }
        break;
    }
    SetConsoleTextAttribute(matrix_color, 0x07);

    for (int k = 0; k < number_matrices; k++) { // создание матриц

        int number_lines;
        double number_elements;
        while (true) {
            cout << "\nenter the number of rows of matrix: \n";
            if (!(cin >> number_lines)) {
                cin.clear();
                cin.ignore();
                cout << "error\n";
                continue;
            }
            cout << "enter the number of elements in each row: \n";
            if (!(cin >> number_elements)) {
                cin.clear();
                cin.ignore();
                cout << "error\n";
                continue;
            }
            break;
        }

        double** array = new double* [number_lines];

        for (int i = 0; i < number_lines; i++) { // строим матрицу A с динамическим выделением памяти

            array[i] = new double[number_elements];
            for (int j = 0; j < number_elements; j++) {
                cout << "enter element " << j + 1 << " of row " << i + 1 << " of matrix " << k + 1 << ": \n";
                while (true) {
                    string arr_exit;
                    if (arr_exit == "end") {
                        return;
                    }
                    if (!(cin >> array[i][j])) {
                        cin.clear();
                        cin.ignore();
                        cout << "error!\n";
                        continue;
                    }
                    break;
                }
            }
        }

        SetConsoleTextAttribute(matrix_color, 0x0a);
        cout << endl << "matrix " << k + 1 << ":\n";
        SetConsoleTextAttribute(matrix_color, 0x07);
        for (int i = 0; i < number_lines; i++) {
            for (int j = 0; j < number_elements; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < number_lines; i++) {
            delete[] array[i];
        }
        delete[] array;
    }
}

//3 подмассива с 4 элементами
// ввод колво матриц
//ввод колво строк?
//ввод колво элементов?
// проверка на перемножение

int main() {
    two_dimensional_array();
    return 0;
}
