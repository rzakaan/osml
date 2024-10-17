#ifndef VEC_H
#define VEC_H

#include <iostream>
#include "object.h"

/**
 *
 *  Example Matrix
 *  __           __
 * |               |
 * | a11  a12  a13 |
 * | a21  a22  a23 |
 * | a31  a32  a33 |
 * |__           __|
 *
 * row-major order
 * a(row, column)
 * */
namespace osml {
    class Vec : public Object {
        double* matrix;
        int intDigits;
        int fracDigits;
        long size;
        int m_row;
        int m_col;
        bool checkSize(Vec& vec);
        void set(int index, double v);
        double get(int index);
        void fill(Vec* target);
        void printArray();
        void calculateDigits(double number);
    public:
        Vec(int row, int column);
        ~Vec();
        int row();
        int col();

        void set(int row, int col, double v);
        double get(int row, int col);

        // constant operation
        void add(double k);
        void sub(double k);
        void mult(double k);
        void div(double k);

        // vector operations
        void add(Vec& vec);
        void sub(Vec& vec);
        void mult(Vec& vec);
        void div(Vec& vec);
        /*
        void inverse();
        void transpose();
        void determinant();*/

        // utils
        Vec* clone();
        void print();

        // operators
        // double operator+(double const& vec);
        // double operator-(double const& vec);
        // double operator*(double const& vec);
        // double operator/(double const& vec);
        // double operator&(double const& vec);
        // double operator|(double const& vec);
        // double operator^(double const& vec);
        // double operator%(double const& vec);

        Vec operator+(Vec vec) {
            Vec temp(vec.row(), vec.col());
            temp.add(vec);
            //temp.add(this);
            return temp;
        }

        friend std::ostream& operator<<(std::ostream& os, Vec& vec) {
            os << "[" << vec.row() << "," << vec.col() << "]";
            return os;
        }
    };
}

#endif // VEC_H
