#pragma once

struct Matrix {
    double** data; // Указатель на двумерный массив
    int rows;      // Количество строк
    int cols;      // Количество столбцов
};

// Базовые функции
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix& m);
Matrix matrix_add(const Matrix& a, const Matrix& b);
Matrix matrix_multiply(const Matrix& a, const Matrix& b);
Matrix matrix_transpose(const Matrix& m);

// Вспомогательные функции
void print_matrix(const Matrix& m);
Matrix matrix_from_array(const double* data, int rows, int cols);

double matrix_sum(const Matrix& m);
