//
//  material.hpp
//  camel_model
//
//  Created by tang zhongbo on 2020/08/27.
//  Copyright © 2020 zero. All rights reserved.
//
#ifndef material_hpp
#define material_hpp

#include <GLUT/GLUT.h>
//
//// attributes of material
static GLfloat ambient[]  = {0.2,0.2,0.2,1.0};
static GLfloat diffuse[]  = {1.0,0.8,0.0,1.0};
static GLfloat specular[] = {1.0,1.0,1.0,1.0};
static GLint shine = 100;

void setMaterial();
#endif /* material_hpp */
