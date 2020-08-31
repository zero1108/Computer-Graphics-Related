//
//  light.hpp
//  camel_model
//
//  Created by tang zhongbo on 2020/08/27.
//  Copyright © 2020 zero. All rights reserved.
//

#ifndef light_hpp
#define light_hpp

#include <GLUT/GLUT.h>

//atributes of first light
static GLfloat diffuse0[]   = {0.5,0.5,0.5,1.0};
static GLfloat ambient0[]   = {0.5,0.5,0.5,1.0};
static GLfloat specular0[]  = {0.5,0.5,0.5,1.0};
static GLfloat light0_pos[] = {1,1,1,1};

//atributes of second light
static GLfloat diffuse1[]   = {0.0,0.0,0.0,1.0};
static GLfloat ambient1[]   = {1.0,0.0,0.0,0.0};
static GLfloat specular1[]  = {1.0,0.0,0.0,0.0};
static GLfloat light1_pos[] = {0.0, 2.0, 1.0, 1.0};

void initLight();
void displayLight();

#endif /* light_hpp */
