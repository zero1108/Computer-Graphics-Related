//
//  point.cpp
//  opengl
//
//  Created by tang zhongbo on 2020/08/26.
//  Copyright © 2020 zero. All rights reserved.
//

#include "point.hpp"


Point::Point() {
   this->x = 0.0;
   this->y = 0.0;
   this->z = 0.0;
}


Point::Point(GLfloat x, GLfloat y, GLfloat z) {
   this->x = x;
   this->y = y;
   this->z = z;
}

/* normalize a vector */

void Point::Normalize() {
    GLfloat d =0.0;
    d = this->x * this->x + this->y * this->y + this->z * this->z;
    d=sqrt(d);
    if(d > 0.0) {
        this->x /= d;
        this->y /= d;
        this->z /= d;
    }
}

Point Point::Subtract(Point a, Point b) {
    Point n;
    return n;
}

