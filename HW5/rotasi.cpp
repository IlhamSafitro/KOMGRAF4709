#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

float angle = 0.0;  // Sudut rotasi dalam derajat

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Matriks rotasi
    glTranslatef(3.0, 6.0, 0.0);  // Pindahkan ke titik awal
    glRotatef(angle, 0.0, 0.0, 1.0);  // Rotasi pada sumbu Z
    glTranslatef(-3.0, -6.0, 0.0);  // Kembalikan ke titik awal

    // Gambar titik awal (3, 6) setelah rotasi
    glBegin(GL_POINTS);
    glVertex2f(3.0, 6.0);
    glEnd();
    
    glFlush();
}

void update(int value) {
    angle += 2.0;  // Kecepatan rotasi dalam derajat per frame
    if (angle > 360.0) {
        angle -= 360.0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);  // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Rotasi");

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}

