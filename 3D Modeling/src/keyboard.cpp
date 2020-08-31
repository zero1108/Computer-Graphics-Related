//
//  keyboard.cpp
//  camel_model
//
//  Created by tang zhongbo on 2020/08/26.
//  Copyright © 2020 zero. All rights reserved.
//

#include "keyboard.hpp"
#include <iostream>

void keyboard(unsigned char key, int x, int y) {
    std::cout << "typing key:" << key << std::endl;
    switch (key) {
        case 'd':
            axix += 1.0;
            glutPostRedisplay();
            break;
        case 'a':
            axix -= 1.0;
            glutPostRedisplay();
            break;
        case 'w':
            z -= 1.0;
            glutPostRedisplay();
            break;
        case 's':
            z += 1.0;
            glutPostRedisplay();
            break;
        case 'k':
            glScalef(0.9, 0.9, 0.9);
            glutPostRedisplay();
            break;
        case 'l':
            glScalef(1.1, 1.1, 1.1);
            glutPostRedisplay();
            break;
        case 'u':
            glRotatef(angle, 0, 1, 0);
            glutPostRedisplay();
            break;
        case 'i':
            glRotatef(angle, 1, 0, 0);
            glutPostRedisplay();
            break;
        case 'o':
            glRotatef(angle, 0, 0, 1);
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
    }


}

void specialkey(int key, int x, int y) {
    std::cout << "typing special key:" << key << std::endl;
    switch(key) {
        case GLUT_KEY_UP:
            glTranslatef(0, OFFSET, 0);
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            glTranslatef(-OFFSET, 0, 0);
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            glTranslatef(0, -OFFSET, 0);
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            glTranslatef(OFFSET, 0, 0);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F11:
            glTranslatef(0, 0, OFFSET);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F12:
            glTranslatef(OFFSET, 0, -OFFSET);
            glutPostRedisplay();
            break;
    }
}
