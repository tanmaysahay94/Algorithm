#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isValidHorizontal(int r, int c, vector<string>& gb) {
    int firstStart = max(c - 4, 0);
    int lastStart = min(c, 5);
    int targetCount = 4;
    for (int start = firstStart, actualCount = 0; start <= lastStart; start++, actualCount = 0) {
        for (int idx = start; idx < start + 5; idx++) {
            if (gb[r][idx] == 'X') {
                actualCount++;
            }
        }
        if (actualCount == targetCount) {
            return true;
        }
    }
    return false;
}
bool isValidVertical(int r, int c, vector<string>& gb) {
    int firstStart = max(r - 4, 0);
    int lastStart = min(r, 5);
    int targetCount = 4;
    for (int start = firstStart, actualCount = 0; start <= lastStart; start++, actualCount = 0) {
        for (int idx = start; idx < start + 5; idx++) {
            if (gb[idx][c] == 'X') {
                actualCount++;
            }
        }
        if (actualCount == targetCount) {
            return true;
        }
    }
    return false;
}
bool isValidDiagonalTL2BR(int r, int c, vector<string>& gb) {
    if (abs(r - c) > 5) {
        return false;
    }
    int firstStartRow = max(r - 4, 0);
    int firstStartCol = c - (r - firstStartRow);
    if (firstStartCol < 0) {
        firstStartRow -= firstStartCol;
        firstStartCol = 0;
    }
    int lastStartRow = min(r, 5);
    int lastStartCol = c - (r - lastStartRow);
    int targetCount = 4;
    for (int startRow = firstStartRow, startCol = firstStartCol, actualCount = 0; startRow <= lastStartRow and startCol <= lastStartCol; startRow++, startCol++, actualCount = 0) {
        for (int rowIdx = startRow, colIdx = startCol; rowIdx < startRow + 5; rowIdx++, colIdx++) {
            if (gb[rowIdx][colIdx] == 'X') {
                actualCount++;
            }
        }
        if (actualCount == targetCount) {
            return true;
        }
    }
    return false;
}
bool isValidDiagonalBL2TR(int r, int c, vector<string>& gb) {
    if (r + c < 4  or r + c > 14) {
        return false;
    }
    int firstStartRow = min(r + 4, 9);
    int firstStartCol = c - (firstStartRow - r);
    if (firstStartCol < 0) {
        firstStartRow += firstStartCol;
        firstStartCol = 0;
    }
    // get last window start
    int lastStartRow = max(r, 4);
    int lastStartCol = r + c - lastStartRow;
    int targetCount = 4;
    for (int startRow = firstStartRow, startCol = firstStartCol, actualCount = 0; startRow >= lastStartRow and startCol <= lastStartCol; startRow--, startCol++, actualCount = 0) {
        for (int rowIdx = startRow, colIdx = startCol; rowIdx > startRow - 5; rowIdx--, colIdx++) {
            if (gb[rowIdx][colIdx] == 'X') {
                actualCount++;
            }
        }
        if (actualCount == targetCount) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<string> gameBoard;
    string line;
    for (int i = 0; i < 10; i++) {
        cin >> line;
        gameBoard.push_back(line);
    }
    bool found = false;
    for (int i = 0; i < 10 and not found; i++) {
        for (int j = 0; j < 10 and not found; j++) {
            if (gameBoard[i][j] == '.') {
                if (isValidHorizontal(i, j, gameBoard)
                        or isValidVertical(i, j, gameBoard)
                        or isValidDiagonalTL2BR(i, j, gameBoard)
                        or isValidDiagonalBL2TR(i, j, gameBoard)) {
                    cout << "YES" << endl;
                    found = true;
                }
            }
        }
    }
    if (not found) {
        cout << "NO" << endl;
    }
    return 0;
}
