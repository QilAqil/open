#include <GL/glut.h>

int x = 200;
bool kanan = true;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void timer(int nilai) {
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void display() { // Renamed from 'd' to 'display' for clarity
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (kanan) {
        x++;
        if (x > 600) {
            kanan = false;
        }
    } else {
        x--;
        if (x < 0) {
            kanan = true; // Corrected from 'benar' to 'true'
        }
    }

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(x, 200.0);      // Use 'x' for horizontal movement
        glVertex2f(x, 400.0);
        glVertex2f(x + 200.0, 400.0);
        glVertex2f(x + 200.0, 200.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) { // Corrected 'batal' to 'int'
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 800) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
    glutCreateWindow("Percobaan Pertama Saya");
    
    init();
    glutDisplayFunc(display);
    // glutIdleFunc(idle); // Uncomment if you want to use idle
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0; // Added return statement
}