#include "matrix.h"
#include <stdexcept>
#include <random>

// Создание матрицы
Matrix create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        m.data[i] = new double[cols](); // инициализация нулями
    }
    return m;
}

// Освобождение памяти
void free_matrix(Matrix& m) {
    if (!m.data) return;
    for (int i = 0; i < m.rows; i++) {
        delete[] m.data[i];
    }
    delete[] m.data;
    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;
}

// Сложение
Matrix matrix_add(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// Умножение
Matrix matrix_multiply(const Matrix& a, const Matrix& b) {
    if (a.cols != b.rows) {
        throw std::invalid_argument("Number of columns in A must equal number of rows in B");
    }
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a.cols; k++) {
                sum += a.data[i][k] * b.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

double matrix_sum(const Matrix& m) {
    if (!m.data) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            sum += m.data[i][j];
        }
    }
    return sum;
}


// Транспонирование
Matrix matrix_transpose(const Matrix& m) {
    Matrix result = create_matrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    return result;
}

// Печать
void print_matrix(const Matrix& m) {
    std::cout << "Matrix " << m.rows << "x" << m.cols << ":\n";
    for (int i = 0; i < m.rows; i++) {
        std::cout << "[ ";
        for (int j = 0; j < m.cols; j++) {
            std::cout << m.data[i][j] << " ";
        }
        std::cout << "]\n";
    }
}

// Из массива
Matrix matrix_from_array(const double* data, int rows, int cols) {
    Matrix result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i * cols + j];
        }
    }
    return result;
}

// Индивидуальное задание: случайная матрица
Matrix matrix_random(int rows, int cols, double min, double max) {
    if (min > max) {
        throw std::invalid_argument("min must be <= max");
    }
    Matrix result = create_matrix(rows, cols);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min, max);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = dist(gen);
        }
    }

    return result;
}
