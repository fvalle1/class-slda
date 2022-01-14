// (C) Copyright 2021, Filippo Valle

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
    ~coordinate()
    {
        x = 0;
        y = 0;
        z = 0;
    };

    friend bool operator==(const coordinate &a, const coordinate &b)
    {
        return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
    };

    friend std::ostream& operator<<(std::ostream& out, const coordinate &data)
    {
        out << "(" << data.x << "," << data.y << "," << data.z << ")";
        return out;
    };
};

typedef coordinate<int> coordinate_int;

#endif