#include <GLUT/glut.h>
#include <cmath>

void drawHouse() {
    // Draw the sky background
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.2, 1.0); // Light blue color for the sky
    glVertex2f(-2.5, -2.5);
    glVertex2f(2.5, -2.5);
    glVertex2f(2.5, 2.5);
    glVertex2f(-2.5, 2.5);
    glEnd();

    // Draw the grassy ground
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.5, 0.3); // Green color for the grass
    glVertex2f(-2.5, -1.0);
    glVertex2f(2.5, -1.0);
    glVertex2f(2.5, -2.5);
    glVertex2f(-2.5, -2.5);
    glEnd();

    // Draw the base of the house
    glBegin(GL_QUADS);
    glColor3f(0.8, 1.9, 0.4); // Brown color for the house
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    // Draw the textured roof of the house
    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.7, 0.3); // Red color for the roof
    glVertex2f(-1.0, 1.0);
    glVertex2f(0.0, 2.0);
    glVertex2f(1.0, 1.0);
    glEnd();

    // Draw the front door
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.1); // Dark brown color for the door
    glVertex2f(-0.2, -1.0);
    glVertex2f(0.2, -1.0);
    glVertex2f(0.2, 0.0);
    glVertex2f(-0.2, 0.0);
    glEnd();

    // Draw two windows on the sides
//    glBegin(GL_QUADS);
//    glColor3f(0.7, 0.5, 0.5); // Light blue color for the windows
//    glVertex2f(-1.0, 0.3);
//    glVertex2f(-0.7, 0.3);
//    glVertex2f(-0.7, 0.6);
//    glVertex2f(-1.0, 0.6);
//
//    glVertex2f(0.7, 0.3);
//    glVertex2f(1.0, 0.3);
//    glVertex2f(1.0, 0.6);
//    glVertex2f(0.7, 0.6);
//    glEnd();

    // Add decorative elements
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.6); // Green color for decorative triangles
    glVertex2f(-0.2, 0.0);
    glVertex2f(0.0, 0.3);
    glVertex2f(0.2, 0.0);
    glEnd();

    // Add a sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.8); // Yellowish color for the sun
    glVertex2f(-1.5, 1.5); // Sun position
    for (float angle = 0.0; angle <= 360.0; angle += 5.0) {
        glVertex2f(-1.5 + 0.2 * cos(angle), 1.5 + 0.2 * sin(angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawHouse();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.5, 2.5, -2.5, 2.5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Beautiful OpenGL House");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background

    glutMainLoop();

    return 0;
}
