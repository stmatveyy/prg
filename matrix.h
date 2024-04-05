#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

class Matrix {
private:
    unsigned int m; // Строки
    unsigned int n; // Столбцы 
    int** data;

public:

    Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
        data = new int* [m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);

    int*& operator[](unsigned int index) { // Возвращая ссылку на указатель, можем обращаться как matrix[][]
        return data[index];
    }

    void fillRandom() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    void fillZeros() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = 0;
            }
        }
    }

    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    void write_to_binary(Matrix& matrix, std::string filename) {
        std::fstream file(filename, std::ios::out | std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            throw std::runtime_error("bruh");
        }

        file.write(reinterpret_cast<char*>(matrix.data), sizeof(matrix.data));

    }

};


std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; ++i) {
        std::cout << " " << std::endl;
        for (unsigned int j = 0; j < matrix.n; ++j) {
            os << std::setw(3) << matrix.data[i][j] << " | "; // setw тут устанавливает фиксированный размер поля для вывода, чтобы красиво было :)
        }
        os << '\n';
    }
    return os;
}

void write_to_file(Matrix &matrix, std::string filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        throw std::runtime_error("bruh");
    }

    file << matrix << std::endl;

}




#endif