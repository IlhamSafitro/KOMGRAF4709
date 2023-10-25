#include <GL/gl.h>
#include <GL/glut.h>

float scaleFactorX = 2.0;  // Faktor scaling pada sumbu X
float scaleFactorY = 1.0;  // Faktor scaling pada sumbu Y

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Matriks scaling
    glTranslatef(3.0, 6.0, 0.0);  // Pindahkan ke titik awal
    glScalef(scaleFactorX, scaleFactorY, 1.0);  // Scaling
    glTranslatef(-3.0, -6.0, 0.0);  // Kembalikan ke titik awal

    // Gambar titik awal (3, 6) setelah scaling
    glBegin(GL_POINTS);
    glVertex2f(3.0, 6.0);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Scaling");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

