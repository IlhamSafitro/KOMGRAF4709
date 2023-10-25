#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

float xTranslation = 2.0;  // Perubahan pada sumbu X
float yTranslation = 0.0;  // Tidak ada perubahan pada sumbu Y

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Matriks translasi
    glTranslatef(xTranslation, yTranslation, 0.0);

    // Gambar titik awal (3, 6) setelah translasi
    glBegin(GL_POINTS);
    glVertex2f(3.0, 6.0);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Translasi");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

