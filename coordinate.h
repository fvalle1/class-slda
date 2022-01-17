// (C) Copyright 2022, Filippo Valle

// written by Filippo Valle filippo.valle@unito.it

// This file is part of slda.

// slda is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or (at your
// option) any later version.

// slda is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA

#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>
#include <iostream>

template <typename T>
struct coordinate
{
    T x;
    T y;
    T z;
    coordinate() : x(0), y(0), z(0){};
    coordinate(T x_, T y_, T z_) : x(x_), y(y_), z(z_){};
    ~coordinate()
    {
        x = 0;
        y = 0;
        z = 0;
    };

    friend bool operator==(const coordinate &a, const coordinate &b)
    {
        return (a.x == b.x) + (a.y == b.y) && (a.z == b.z);
    };

    //element-wise ==
    friend coordinate operator-(const coordinate &a, const coordinate &b)
    {
        return coordinate(static_cast<T>(a.x == b.x),
                          static_cast<T>(a.y == b.y),
                          static_cast<T>(a.z == b.z));
    };

    friend coordinate operator+(const coordinate &a, const coordinate &b)
    {
        return coordinate(a.x + b.x,
                          a.y + b.y,
                          a.z + b.z);
    };

    friend coordinate& operator+=(coordinate &a, const coordinate &b)
    {
        a = a+b;
        return a;
    };

    // count how many items are equal
    // sort of weighted == to estimate weighted accuracy 
    friend double operator||(const coordinate &a, const coordinate &b)
    {
        static double t = 1./3.;
         return ((a.x == b.x) ? t:0.) + ((a.y == b.y) ? t:0.) + ((a.z == b.z) ? t:0.);
    };

    friend std::ostream &operator<<(std::ostream &out, const coordinate &data)
    {
        out << "(" << data.x << "," << data.y << "," << data.z << ")";
        return out;
    };

    T operator[](const uint8_t i) const //getter
    {
        switch (i)
        {
        case 0:
            return this->x;
            break;
        case 1:
            return this->y;
            break;
        case 2:
            return this->z;
            break;
        default:
            throw std::out_of_range("index out of range");
            break;
        }
    }

    T& operator()(const uint8_t i) //setter (note T&)
    {
        switch (i)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            throw std::out_of_range("index out of range");
            break;
        }
    }

    static constexpr uint8_t size(){return 3;}//only harcoded here
};

typedef coordinate<int> coordinate_int;

#endif