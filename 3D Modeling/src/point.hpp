//
//  point.hpp
//  opengl
//
//  Created by tang zhongbo on 2020/08/26.
//  Copyright © 2020 zero. All rights reserved.
//
#pragma once

#ifndef point_hpp
#define point_hpp

#include <GLUT/GLUT.h>
#include <cmath>

class Point {
    public:
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
    Point();
    Point(GLfloat x, GLfloat y, GLfloat z);
    void Normalize();
    Point Subtract(Point a, Point b);

};

#endif /* point_hpp */
