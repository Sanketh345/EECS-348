#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;


void readMatrixFromFile(const char* filename, int matrix[MAX_SIZE][MAX_SIZE], int& n, bool secondMatrix = false);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int n);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE] = {};
    int matrixB[MAX_SIZE][MAX_SIZE] = {};
    int resultMatrix[MAX_SIZE][MAX_SIZE] = {};
    int n;

    readMatrixFromFile("matrix_input.txt", matrixA, n);
    readMatrixFromFile("matrix_input.txt", matrixB, n, true);

    std::cout << "Sanketh" << std::endl;
    std::cout << "Lab #6: Matrix Manipulation" << std::endl << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, n);
    std::cout << std::endl;

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, n);
    std::cout << std::endl;

    addMatrices(matrixA, matrixB, resultMatrix, n);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(resultMatrix, n);
    std::cout << std::endl;

    multiplyMatrices(matrixA, matrixB, resultMatrix, n);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(resultMatrix, n);
    std::cout << std::endl;

    subtractMatrices(matrixA, matrixB, resultMatrix, n);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(resultMatrix, n);

    return 0;
}

void readMatrixFromFile(const char* filename, int matrix[MAX_SIZE][MAX_SIZE], int& n, bool secondMatrix){
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening " << filename << ". Check if the file exists and is readable." << std::endl;
        exit(1);
    }

    file >> n;
    if (secondMatrix) {
        for (int skip = 0; skip < n * n; ++skip) {
            int temp;
            file >> temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }
}


void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
