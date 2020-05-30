#pragma once
#include <cstddef>
#include <memory>
#include "exception.hpp"

template <typename T>
using shared_ptr = std::shared_ptr<T>;


template <size_t N, typename T>
class Matrix {
    T _data[N][N];

public:
    Matrix();
    Matrix(const std::initializer_list<T> &init_list);
    Matrix(const Matrix &) = delete;
    Matrix &operator=(const Matrix &) = delete;
    void resetMatrix();

    T &at(size_t row, size_t column);
    void mulRight(const Matrix &matrix);
};


template <size_t N, typename T>
class MathVec {
    T _data[N];
public:
    MathVec();
    MathVec(const MathVec &) = delete;
    MathVec &operator=(const MathVec &) = delete;
    void resetVec();
    void mulLeft(const Matrix<N, T> &matrix);
    T &at(size_t pos);
};

#include "implementation/matrix.hpp"