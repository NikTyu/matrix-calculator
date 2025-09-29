#pragma once
#include <iostream>

struct Matrix {
    double** data;
    int rows;
    int cols;
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

// Индивидуальное задание: сумма элементов матрицы
double matrix_sum(const Matrix& m);
