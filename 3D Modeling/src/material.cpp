//
//  material.cpp
//  camel_model
//
//  Created by tang zhongbo on 2020/08/27.
//  Copyright © 2020 zero. All rights reserved.
//

#include "material.hpp"

void setMaterial() {
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMateriali(GL_FRONT,GL_SHININESS,shine);
}
