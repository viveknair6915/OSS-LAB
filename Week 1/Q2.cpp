#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    size_t rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:" << endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << "Element at (" << i << "," << j << "): ";
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> transposed = transposeMatrix(matrix);
    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    cout << "Transposed matrix:" << endl;
    printMatrix(transposed);
    return 0;
}
