#include <iostream>
#include <vector>
using namespace std;

bool esValido(vector<vector<int>>& board, int fila, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (board[fila][x] == num || board[x][col] == num)
            return false;

    int startFila = fila - fila % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startFila][j + startCol] == num)
                return false;
    return true;
}

bool resolverSudoku(vector<vector<int>>& board, int fila, int col) {
    if (fila == 9) return true;
    if (col == 9) return resolverSudoku(board, fila + 1, 0);
    if (board[fila][col] != 0) return resolverSudoku(board, fila, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (esValido(board, fila, col, num)) {
            board[fila][col] = num;
            if (resolverSudoku(board, fila, col + 1))
                return true;
            board[fila][col] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> sudoku = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    resolverSudoku(sudoku, 0, 0);

    cout << "Sudoku resuelto:\n";
    for (auto& fila : sudoku) {
        for (int n : fila) cout << n << " ";
        cout << endl;
    }
}








