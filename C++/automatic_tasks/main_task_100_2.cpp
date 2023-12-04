#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class GameOfLife {
public:
    GameOfLife(int size, int max_years, const vector<char>& symbols) : size(size), max_years(max_years), symbols(symbols) {
        srand(time(0));
        grid.resize(size, vector<int>(size, 0));
        initialize_grid_manually();
    }

    void initialize_grid_manually() {
        cout << "\nenter the initial state:" << endl;

        // cоздаем массив в котором все строки состоят из уникальных символов
        vector<vector<char>> unique_grid(size, vector<char>(size, 0));
        for (int i = 0; i < size; ++i) {
            random_shuffle(symbols.begin(), symbols.end());
            unique_grid[i] = symbols;
        }

        // выводим массив для удобства пользователя
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << unique_grid[i][j] << " ";
            }
            cout << endl;
        }

        // случайным образом выбираем один из уникальных символов и обновляем основную матрицу
        int random_row_index = rand() % size;
        selected_symbol = unique_grid[random_row_index][0];

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = (unique_grid[i][j] == selected_symbol) ? 1 : 0;
            }
        }

        cout << "\nselected symbol for adaptation: " << selected_symbol << endl << endl;
    }

    /*void printGrid() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    void print_grid() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] > 0) {
                    // Зеленый цвет для живых клеток
                    cout << "\033[42m  \033[0m";
                }
                else {
                    cout << "\033[47;90m  \033[0m"; // gray 
                }
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void simulate_life() {
        for (int year = 1; year <= max_years; ++year) {
            cout << "generation " << year << ":" << endl;
            print_grid();

            evolve();

            if (is_game_over()) {
                cout << "\nGame over" << endl;
                break;
            }
        }
    }

private:
    void evolve() {
        vector<vector<int>> new_grid(size, vector<int>(size, 0));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int live_neighbors = count_live_neighbors(i, j);

                if (grid[i][j] > 0 && grid[i][j] < 12) {
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        new_grid[i][j] = grid[i][j] + 1;
                    }
                    else {
                        new_grid[i][j] = 0;
                    }
                }
                else if (grid[i][j] == 0) {
                    new_grid[i][j] = 1;
                }
                else if (grid[i][j] == 12) {
                    new_grid[i][j] = 0;
                }
            }
        }

        grid = new_grid;
    }

    int count_live_neighbors(int x, int y) const {
        int live_neighbors = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newX = x + i;
                int newY = y + j;

                if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
                    live_neighbors += grid[newX][newY];
                }
            }
        }

        live_neighbors -= grid[x][y];

        return live_neighbors;
    }

    bool is_game_over() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] > 0) {
                    return false;
                }
            }
        }
        return true;
    }

    int size;
    int max_years;
    vector<vector<int>> grid;
    vector<char> symbols;
    char selected_symbol;
};

vector<char> generate_alphabet_symbols(int count) {
    vector<char> symbols;
    for (char ch = 'a'; ch < 'a' + count; ++ch) {
        symbols.push_back(ch);
    }
    return symbols;
}

int main() {
    int size, max_years;
    cout << "Enter matrix size: ";
    while (true) {
        if (!(cin >> size)) {
            cin.clear();
            cin.ignore();
            cout << "\nerror!\n\n";
            continue;
        }
        break;
    }

    int unique_symbol_count;
    cout << "Enter the number of unique symbols: ";
    while (true) {
        if (!(cin >> unique_symbol_count)) {
            cin.clear();
            cin.ignore();
            cout << "\nerror!\n\n";
            continue;
        }
        break;
    }

    vector<char> symbols = generate_alphabet_symbols(unique_symbol_count);

    cout << "Enter the maximum number of generations: ";
    while (true) {
        if (!(cin >> max_years)) {
            cin.clear();
            cin.ignore();
            cout << "\nerror!\n\n";
            continue;
        }
        break;
    }

    GameOfLife game(size, max_years, symbols);
    game.simulate_life();

    return 0;
}


//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//using namespace std;
//
//class GameOfLife {
//public:
//    GameOfLife(int size, int maxYears, const vector<char>& symbols) : size(size), maxYears(maxYears), symbols(symbols) {
//        srand(time(0));
//        grid.resize(size, vector<int>(size, 0));
//        initializeGridManually();
//    }
//
//    void initializeGridManually() {
//        cout << "\nenter the initial state:" << endl;
//
//        // cоздаем массив в котором все строки состоят из уникальных символов
//        vector<vector<char>> uniqueGrid(size, vector<char>(size, 0));
//        for (int i = 0; i < size; ++i) {
//            random_shuffle(symbols.begin(), symbols.end());
//            uniqueGrid[i] = symbols;
//        }
//
//        // выводим массив для удобства пользователя
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                cout << uniqueGrid[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//        // случайным образом выбираем один из уникальных символов и обновляем основную матрицу
//        int randomRowIndex = rand() % size;
//        selectedSymbol = uniqueGrid[randomRowIndex][0];
//
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                grid[i][j] = (uniqueGrid[i][j] == selectedSymbol) ? 1 : 0;
//            }
//        }
//
//        cout << "\nselected symbol for adaptation: " << selectedSymbol << endl << endl;
//    }
//
//    /*void printGrid() const {
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                cout << grid[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }*/
//
//    void printGrid() const {
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                if (grid[i][j] > 0) {
//                    // Зеленый цвет для живых клеток
//                    cout << "\033[42m  \033[0m";
//                }
//                else {
//                    cout << "\033[47;90m  \033[0m"; // gray 
//                }
//            }
//            cout << endl;
//        }
//        cout << endl;
//
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                cout << grid[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//
//    void simulateLife() {
//        for (int year = 1; year <= maxYears; ++year) {
//            cout << "generation " << year << ":" << endl;
//            printGrid();
//
//            evolve();
//
//            if (isGameOver()) {
//                cout << "\nGame over" << endl;
//                break;
//            }
//        }
//    }
//
//private:
//    void evolve() {
//        vector<vector<int>> newGrid(size, vector<int>(size, 0));
//
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                int liveNeighbors = countLiveNeighbors(i, j);
//
//                if (grid[i][j] > 0 && grid[i][j] < 12) {
//                    // Microbe with life level 1 to 11
//                    if (liveNeighbors == 2 || liveNeighbors == 3) {
//                        newGrid[i][j] = grid[i][j] + 1;
//                    }
//                    else {
//                        newGrid[i][j] = 0; // Microbe dies
//                    }
//                }
//                else if (grid[i][j] == 0) {
//                    // New microbe is born
//                    newGrid[i][j] = 1;
//                }
//                else if (grid[i][j] == 12) {
//                    // Microbe dies from old age, no regeneration
//                    newGrid[i][j] = 0;
//                }
//            }
//        }
//
//        grid = newGrid;
//    }
//
//    int countLiveNeighbors(int x, int y) const {
//        int liveNeighbors = 0;
//
//        for (int i = -1; i <= 1; ++i) {
//            for (int j = -1; j <= 1; ++j) {
//                int newX = x + i;
//                int newY = y + j;
//
//                if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
//                    liveNeighbors += grid[newX][newY];
//                }
//            }
//        }
//
//        // Exclude the current cell
//        liveNeighbors -= grid[x][y];
//
//        return liveNeighbors;
//    }
//
//    bool isGameOver() const {
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                if (grid[i][j] > 0) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//    int size;
//    int maxYears;
//    vector<vector<int>> grid;
//    vector<char> symbols;
//    char selectedSymbol;
//};
//
//vector<char> generateAlphabetSymbols(int count) {
//    vector<char> symbols;
//    for (char ch = 'a'; ch < 'a' + count; ++ch) {
//        symbols.push_back(ch);
//    }
//    return symbols;
//}
//
//int main() {
//    int size, maxYears;
//    cout << "Enter matrix size: ";
//    cin >> size;
//
//    int uniqueSymbolCount;
//    cout << "Enter the number of unique symbols: ";
//    cin >> uniqueSymbolCount;
//
//    vector<char> symbols = generateAlphabetSymbols(uniqueSymbolCount);
//
//    cout << "Enter the maximum number of generations: ";
//    cin >> maxYears;
//
//    GameOfLife game(size, maxYears, symbols);
//    game.simulateLife();
//
//    return 0;
//}
