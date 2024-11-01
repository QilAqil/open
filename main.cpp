#include <GL/glut.h> // g

int x = 200;
bool kanan = true;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

/*void idle() {
glutPostRedisplay();
}*/

void timer(int nilai) { // value
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void display() { // d
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (kanan) {
        x++;
        //glTranslatef(1.0, 0.0, 0.0); tidak di pakai
        if (x > 600) {
            kanan = false;
        }
    } else {
        x--;
        // glTranslatef(-1.0, 0.0, 0.0);
        if (x < 0) {
            kanan = true;
        }
    }

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(x, 200.0);      // x horisontal
        glVertex2f(x, 400.0);
        glVertex2f(x + 200.0, 400.0);
        glVertex2f(x + 200.0, 200.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) { // void ganti int
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 800) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
    glutCreateWindow("Percobaan Pertama Saya");
    
    init();
    glutDisplayFunc(display); //d ganti display
    // glutIdleFunc(idle); 
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0; // tambah return statement
}