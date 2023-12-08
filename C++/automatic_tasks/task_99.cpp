// The code uses the snake_case naming style for functions and variables.
// CamelCase is used for classes and namespace.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>          // готово 

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


// генерация случайного четырехзначного числа без повторяющихся цифр
int generate_number() {

    srand(time(0));
    
    int number;
    // массив для отслеживания использованных цифр
    bool digits[10] = { false };

    do {
        // генерация случайного четырехзначного числа
        number = rand() % 9000 + 1000;  //  в диапазоне от 1000 до 9999
    } while (digits[number % 10] || digits[(number / 10) % 10] || digits[(number / 100) % 10] || digits[number / 1000]);
       // проверка - что все цифры числа различны - если хотя бы одна цифра уже использована цикл повторяется

    return number;
}

bool is_valid_input(int number) {
    if (number < 1000 || number > 9999) {
        return false; // не четырехзначное число
    }

    return true;
}

void check_guess(int secret_number, int user_number, int& pluses, int& minuses) {
    pluses = minuses = 0;

    // сравнение цифр загаданного числа и числа пользователя
    for (int i = 0; i < 4; ++i) {
        // извлечение i-той цифры из загаданного числа
        int secret_digit = (secret_number / static_cast<int>(pow(10, 3 - i))) % 10;
        // извлечение i-той цифры из загаданного числа
        int user_digit = (user_number / static_cast<int>(pow(10, 3 - i))) % 10;

        // сравнение цифр загаданного числа и числа пользователя
        if (secret_digit == user_digit) {
            // если цифры совпадают - увеличиваем количество плюсов
            ++pluses;
        }
        else {
            // если цифры не совпадают - начинаем вложенный цикл для поиска минусов

            for (int j = 0; j < 4; ++j) {
                // извлечение j-той цифры из загаданного числа для сравнения с цифрой пользователя
                int temp_secret_digit = (secret_number / static_cast<int>(pow(10, 3 - j))) % 10;
                
                // если цифры совпадают и не находятся на одной и той же позиции - увеличиваем количество минусов
                if (temp_secret_digit == user_digit && i != j) {
                    ++minuses;
                    break;
                }
            }
        }
    }
}

void set_color(int color) {
    SetConsoleTextAttribute(console, color);
}

int main() {
    int secret_number = generate_number();
    int user_number, pluses, minuses, attempts = 0;

    //set_color(14);
    const WORD textColor = 0xE;
    const WORD bgColor = 0x70;

    SetConsoleTextAttribute(console, textColor | (bgColor << 4));

    cout << "Welcome to the game 'Bulls and Cows!'\n\n";
    cout << "The computer guessed a four-digit number. Try to guess!\n\n";
    SetConsoleTextAttribute(console, 15);
    set_color(15);



    set_color(14);
    cout << "number: " << secret_number << "\n\n";
    set_color(15);



    do {
        do {
            while (true) {
                set_color(11);
                cout << "enter number: ";
                set_color(15);
                if (!(cin >> user_number)) {
                    cin.clear();
                    cin.ignore();
                    set_color(12);
                    cout << "error!\n";
                    set_color(15);
                    continue;
                }
                break;
            }

            if (!is_valid_input(user_number)) {
                set_color(12);
                cout << "\nerror!\n";
                set_color(15);
            }
        } while (!is_valid_input(user_number));

        check_guess(secret_number, user_number, pluses, minuses);

        set_color(13);
        cout << "\nresult: " << pluses << " pluses and " << minuses << " minuses! \n";
        set_color(15);

        ++attempts;
    } while (pluses < 4);

    set_color(10);
    cout << "\ncongratulations! U guessed the number " << secret_number << " in " << attempts << " attempts!\n";
    set_color(15);

    return 0;
}
