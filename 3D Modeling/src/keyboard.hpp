//
//  keyboard.hpp
//  camel_model
//
//  Created by tang zhongbo on 2020/08/26.
//  Copyright © 2020 zero. All rights reserved.
//
#ifndef keyboard_hpp
#define keyboard_hpp


#include <cstdlib>
#include "point.hpp"

const float OFFSET = 0.5;

static GLdouble axix = 0.0, axiy = 0.0, z = 0.0;
static bool rotating = false;
static GLfloat angle = 15.0;
void keyboard(unsigned char key, int x, int y);
void specialkey(int key, int x, int y);

#endif /* keyboard_hpp */
