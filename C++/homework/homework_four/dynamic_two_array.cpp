//Using snake_case! Using camelCase for class!
#include<iostream>
#include<Windows.h>
#include<time.h>

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

    int number_lines, number_elements;

    double*** all_matrices = new double** [number_matrices]; // создаем массив для
    //хранения всех двумерных массивов

    for (int k = 0; k < number_matrices; k++) { // создание матриц

        while (true) {
            cout << "\nenter the number of rows of matrix " << k + 1 << ": \n";
            if (!(cin >> number_lines) or (number_lines <= 1)) {
                cin.clear();
                cin.ignore();
                cout << "error\n";
                continue;
            }
            cout << "enter the number of elements in each row " << k + 1 << ": \n";
            if (!(cin >> number_elements) or (number_elements <= 1)) {
                cin.clear();
                cin.ignore();
                cout << "error\n";
                continue;
            }
            break;
        }

        double** array = new double* [number_lines];
        all_matrices[k] = array;
        string arr_exit;

        for (int i = 0; i < number_lines; i++) { // строим матрицу A с выделением памяти
            array[i] = new double[number_elements];

            for (int j = 0; j < number_elements; j++) {
                cout << "enter element " << j + 1 << " of row " << i + 1 << " of matrix " << k + 1 << ": \n";
                while (true) {
                    if (!(cin >> array[i][j])) {
                        cin.clear();
                        cin.ignore();
                        cout << "error!\n";
                        continue;
                    }
                    break;
                    //if (arr_exit == "exit" or arr_exit == "end") {
                    //    return;
                    //}
                }
            }
        }
    }

    // Вывод всех матриц
    SetConsoleTextAttribute(matrix_color, 0x0a);
    for (int k = 0; k < number_matrices; k++) {
        cout << "\nMatrix " << k + 1 << ":\n";
        SetConsoleTextAttribute(matrix_color, 0x07);

        for (int i = 0; i < number_lines; i++) {
            for (int j = 0; j < number_elements; j++) {
                cout << all_matrices[k][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    SetConsoleTextAttribute(matrix_color, 0x07);

    SetConsoleTextAttribute(matrix_color, 0x0a);
    cout << "\nwhat to do with matrices?\n";
    SetConsoleTextAttribute(matrix_color, 0x07);
    cout << "if not, then enter ";
    SetConsoleTextAttribute(matrix_color, 0x0a);
    cout << "'exit'";
    SetConsoleTextAttribute(matrix_color, 0x07);
    cout << "!";
    cout << "\nif yes, enter the action sign : ";
    SetConsoleTextAttribute(matrix_color, 0x0a);
    cout << "' + ', ' - ', ' / ', ' * '";
    SetConsoleTextAttribute(matrix_color, 0x07);
    cout << "!\n";

    char actions_matrix;


    //использовать switch case и иницилизации




    while (true) {
        cin >> actions_matrix;
        switch (actions_matrix) {
        case '+':
            cout << "the result of adding two-dimensional arrays (matrices): \n\ntwo-dimensional array (matrix):\n";
            if (number_matrices >= 2) {

                try {
                    double** result_matrix = new double* [number_lines];

                    for (int i = 0; i < number_lines; i++) {
                        result_matrix[i] = new double[number_elements];

                        for (int j = 0; j < number_elements; j++) {
                            result_matrix[i][j] = 0;

                            for (int k = 0; k < number_matrices; k++) {
                                result_matrix[i][j] += all_matrices[k][i][j];
                            }

                            cout << result_matrix[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                catch (const exception& err) {
                    cout << "error! failed to allocate memory!\n" << err.what() << endl;
                }
            }
            else {
                cout << "error! not enough matrices to add!\n";
            }
            //cout << "sum of matrices: \n";
            break;

        case '-':  //исправить с минусом
            cout << "the result of difference two-dimensional arrays (matrices): \n\ntwo-dimensional array (matrix):\n";

            if (number_matrices >= 2) {
                cout << "\nDifference of matrices:\n";
                try {
                    double** result_matrix = new double* [number_lines];

                    for (int i = 0; i < number_lines; i++) {
                        result_matrix[i] = new double[number_elements];

                        for (int j = 0; j < number_elements; j++) {
                            result_matrix[i][j] = all_matrices[0][i][j]; // Initialize with the first matrix

                            try {
                                for (int k = 1; k < number_matrices; k++) {
                                    result_matrix[i][j] -= all_matrices[k][i][j];
                                }
                            }
                            catch (const exception& e) {
                                cout << "Error: " << e.what() << endl;
                                // Handle the error as needed
                            }

                            cout << result_matrix[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                catch (const exception& rr) {
                    cout << "Error: Memory allocation failed." << endl;
                }
            }
            else {
                cout << "Error: Not enough matrices for subtraction.\n";
            }

            break;
        case '/':
            cout << "quotient of matrices: \n";

            break;
        case '*':
            cout << "product of matrices: \n";

            break;
        case 'exit':
            cout << "end! \n";
            return;
            break;
        default:
            cout << "error!\n";
            break;
        }
    }
}


class void_vector {
public:
    clock_t zero_user = clock();

    void zero_recurrent(int arr_set) {
        cerr << arr_set << " \n";
        
        try {
            if (arr_set == 0) {
                return;
            }
            switch (arr_set) {
            case 1:
                cout << arr_set - 1 << endl;
                break;
            case 2:
                cout << arr_set - 2 << endl;
                break;
            case 3:
                cout << arr_set - 3 << endl;
                break;
            case 4:
                cout << arr_set - 4 << endl;
                break;
            default:
                cerr << arr_set << endl;
                break;
            }
        }
        catch (const exception& err) {
            cout << "return 1" << err.what();
        }
    }

    clock_t one_user = clock();
    double spent_time = (double)(zero_user - one_user) / CLOCKS_PER_SEC;
    
//private:
//    const int return_function = 0, const return_claster = 0;
//    int** local_array = new int*[return_function];
//    for (int k = 0; k < arr_set; k++) {
//        local_array[k] = new int[return_claster];
//    }
};

int main() {
    //two_dimensional_array()

    void_vector long_long;
    long_long.zero_recurrent(2);

    return 0;
}
