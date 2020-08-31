#include <iostream>
#include <GLTools.h>
#include <GLUT/GLUT.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include "point.hpp"
#include "keyboard.hpp"
#include "material.hpp"
#include "light.hpp"

using namespace std;

struct texture {
    GLfloat tu;
    GLfloat tv;
};

struct face {
    int v[4];
    int t[4];
    int n[4];
};

typedef Point normal;

vector<Point> vArr;
vector<texture> vtArr;
vector<normal> vnArr;
vector<face> fArr;

enum drawType {TRIANGLE, QUARD};
drawType dType = QUARD;

int winHeight = 750;
int winWidth = 750;


void drawQuads() {
    glBegin(GL_QUADS);
    for(int i = 0; i < fArr.size(); i++) {
        // 0 1 2 3 | 0 1 2
        for(int j = 0; j < 4; j++) {
//            glTexCoord2f(vtArr[fArr[i].t[j]].tu,vtArr[fArr[i].t[j]].tv);
            glNormal3f(vnArr[fArr[i].n[j]].x, vnArr[fArr[i].n[j]].y, vnArr[fArr[i].n[j]].z);
            glVertex3f(vArr[fArr[i].v[j]].x, vArr[fArr[i].v[j]].y, vArr[fArr[i].v[j]].z);
        }
    }
        
    glEnd();
}

void drawTriangles() {
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < fArr.size(); i++) {
        
        // 0 1 2 3 | 0 1 2
        for(int j = 0; j < 3; j++) {
//            glTexCoord2f(vtArr[fArr[i].t[j]].tu,vtArr[fArr[i].t[j]].tv);
            glNormal3f(vnArr[fArr[i].n[j]].x, vnArr[fArr[i].n[j]].y, vnArr[fArr[i].n[j]].z);
            glVertex3f(vArr[fArr[i].v[j]].x, vArr[fArr[i].v[j]].y, vArr[fArr[i].v[j]].z);
        }
        
        // 0 1 2 3 | 0 2 3
        for(int j = 0; j < 4; j++) {
            if(j != 1) {
//                glTexCoord2f(vtArr[fArr[i].t[j]].tu,vtArr[fArr[i].t[j]].tv);
                glNormal3f(vnArr[fArr[i].n[j]].x, vnArr[fArr[i].n[j]].y, vnArr[fArr[i].n[j]].z);
                glVertex3f(vArr[fArr[i].v[j]].x, vArr[fArr[i].v[j]].y, vArr[fArr[i].v[j]].z);
            }
        }
    }
    glEnd();
}

// draw obj model from the stored data
void drawObj() {
    if(dType == QUARD) {
        drawQuads();
    }
    else if(dType == TRIANGLE) {
        drawTriangles();
    }
}

void readFile(string name) {
    ifstream in(name);
    string line, str;
    istringstream is;
    char ch;
    face     *f;
    Point    *point;
    normal   *vn;
    texture  *vt;
    while(in.good() && !in.eof()) {
        getline(in, line);
        ch = in.get();
        if(ch == 'v') {
            ch = in.get();
            if(ch == 't') {
                vt = new texture();
                in >> vt->tu >> vt->tv;
                vtArr.push_back(*vt);
            }
            else if(ch == 'n') {
                vn = new normal();
                in >> vn->x >> vn->y >> vn->z;
                vnArr.push_back(*vn);
            }
            else {
                point = new Point();
                in >> point->x >> point->y >> point->z;
                vArr.push_back(*point);
            }
        }
        else if(ch == 'f'){
            ch = in.get();
            if(ch == ' ') {
                f = new face();
                for(int i = 0; i < 4; i++) {
                    in >> line;
                    line = regex_replace(line, regex("/"), " ");
                    is.str(line);
                    is >> f->v[i] >>f->t[i] >> f->n[i];
                    f->v[i] -= 1;
                    f->t[i] -= 1;
                    f->n[i] -= 1;
                    is.clear();
                }
                fArr.push_back(*f);
            }
        }
    }
    is.clear();

    cout << "finish reading obj file" << endl;
    cout << "total vertices: " << vArr.size() << endl;
    cout << "total normals: " << vnArr.size()  << endl;
    cout << "total textures: " << vtArr.size()  << endl;
    cout << "total faces: " << fArr.size()  << endl;
    in.close();
}

void drawTriangle() {
    GLfloat vVerts[] = {
        -1.5f,0.0f,0.0f,
        0.5f,0.0f,0.0f,
        0.0f,0.5f,0.0f,
    };
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3fv(&vVerts[0]);
    glVertex3fv(&vVerts[1]);
    glVertex3fv(&vVerts[2]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawObj();
//    drawTriangle();
    displayLight();
    glutSwapBuffers();
}

void init() {
    glClearColor (0.0, 0.0, 0.0, 1.0);
    initLight();
//    setMaterial();
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -50.0, 50.0, 0.0, 100.0);
}

void myReshape(GLsizei width, GLsizei height) {
    // Set the viewport to cover the new window
//    glViewport(0.0, 0.0, width, height);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45.0, (GLfloat) width/(GLfloat) height, 1.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
    gluLookAt(5.0, -180.0, 120.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    
    winWidth = width;
    winHeight = height;
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    readFile("camel.obj");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("camel-model");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    init();
    // enroll keyboard operations
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialkey);

    glutMainLoop();
    return 0;
}
