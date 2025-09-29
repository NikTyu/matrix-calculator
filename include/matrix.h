#pragma once
#include <iostream>

struct Matrix {
    double** data;
    int rows;
    int cols;
};

// =====================
// Базовые функции
// =====================

// Создание матрицы
Matrix create_matrix(int rows, int cols);

// Освобождение памяти
void free_matrix(Matrix& m);

// Сложение матриц
Matrix matrix_add(const Matrix& a, const Matrix& b);

// Умножение матриц
Matrix matrix_multiply(const Matrix& a, const Matrix& b);

// Транспонирование
Matrix matrix_transpose(const Matrix& m);

// =====================
// Вспомогательные функции
// =====================

// Печать матрицы
void print_matrix(const Matrix& m);

// Создание из одномерного массива
Matrix matrix_from_array(const double* data, int rows, int cols);

// Сумма всех элементов матрицы
double matrix_sum(const Matrix& m);


// =====================
// Индивидуальное задание
// =====================

// Создание случайной матрицы
Matrix matrix_random(int rows, int cols, double min, double max);
