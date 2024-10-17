#include "vec.h"

#include <iostream>
#include <iomanip>
#include <math.h>

namespace osml
{
    Vec::Vec(int row, int col) {
        m_row = row;
        m_col = col;
        size = row * col;
        matrix = new double[size];
        intDigits = 0;
        fracDigits = 0;
    }

    Vec::~Vec() {
        delete[] matrix;
    }

    Vec* Vec::clone() {
        Vec* obj = new Vec(row(), col());
        fill(obj);
        obj->set(0, 0, 3.14);
        obj->printArray();
        return obj;
    }

    //* setter & getter
    int Vec::row() {
        return m_row;
    }

    int Vec::col() {
        return m_col;
    }

    //* private functions
    bool Vec::checkSize(Vec& vec) {
        if (row() == vec.row() && col() == vec.col()) {
            return true;
        }
        else {
            return false;
        }
    }

    //* util functions
    void Vec::fill(Vec* target) {
        for (int i = 0; i < size; i++) {
            target->set(i, matrix[i]);
        }
    }

    void Vec::calculateDigits(double number) {
        // calculate integer digits
        int integerDigits = 0;
        double integerPart = std::floor(number);
        if (integerPart == 0) {
            integerDigits = 1;
        }
        else {
            integerDigits = static_cast<int>(std::log10(integerPart)) + 1;
        }

        // calculate fractional digits
        int fractionalDigits = 0;
        double fractionalPart = number - integerPart;
        if (fractionalPart != 0) {
            while (fractionalPart > 0 && fractionalDigits < std::numeric_limits<double>::digits10) {
                fractionalPart *= 10;
                fractionalPart -= std::floor(fractionalPart);
                fractionalDigits++;
            }
        }

        if (integerDigits > intDigits) intDigits = integerDigits;
        if (fractionalDigits > fracDigits) fracDigits = fractionalDigits;
    }

    void Vec::printArray() {
        //* for debugging
        std::cout << "|-> r:" << row() << " c:" << col() << " [";
        for (int i = 0; i < size; i++) {
            std::cout << matrix[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    void Vec::print() {
        std::cout << "|-> vector row:" << row() << " col:" << col() << std::endl;
        //printArray();

        for (int r = 0; r < row(); r++) {
            for (int c = 0; c < col(); c++) {
                if (c == 0) {
                    std::cout << "| ";
                }

                int index = (r * row()) + c;
                //std::cout << std::fixed;
                std::cout << std::setw(intDigits);
                //std::cout << std::setprecision(2);
                std::cout << matrix[index] << " ";

                if (c == col() - 1) {
                    std::cout << "|" << std::endl;
                }
            }
        }
    }

    //* vector setter getter
    void Vec::set(int index, double v) {
        matrix[index] = v;
        calculateDigits(v);
    }

    void Vec::set(int row, int col, double v) {
        long index = (row * m_row) + col;
        matrix[index] = v;
        calculateDigits(v);
    }

    double Vec::get(int row, int col) {
        long index = (row * m_row) + col;
        return matrix[index];
    }

    double Vec::get(int index) {
        return matrix[index];
    }

    //* vector math functions
    void Vec::add(Vec& vec) {
        if (!checkSize(vec)) return;
        for (int i = 0; i < size; i++) {
            matrix[i] += vec.get(i);
        }
    }

    void Vec::sub(Vec& vec) {
        if (!checkSize(vec)) return;
        for (int i = 0; i < size; i++) {
            matrix[i] -= vec.get(i);
        }
    }

    void Vec::mult(Vec& vec) {
        if (!checkSize(vec)) return;
        for (int i = 0; i < size; i++) {
            matrix[i] *= vec.get(i);
        }
    }

    void Vec::div(Vec& vec) {
        if (!checkSize(vec)) return;
        for (int i = 0; i < size; i++) {
            matrix[i] /= vec.get(i);
        }
    }

    //* constant math operations
    void Vec::add(double k) {
        for (int i = 0; i < size; i++) {
            matrix[i] += k;
        }
    }

    void Vec::sub(double k) {
        for (int i = 0; i < size; i++) {
            matrix[i] -= k;
        }
    }

    void Vec::mult(double k) {
        for (int i = 0; i < size; i++) {
            matrix[i] *= k;
        }
    }

    void Vec::div(double k) {
        for (int i = 0; i < size; i++) {
            matrix[i] /= k;
        }
    }
} // namespace osml

