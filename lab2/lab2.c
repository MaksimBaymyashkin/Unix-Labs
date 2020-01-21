#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void display() {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glBegin(GL_QUADS);
  glColor3f(0.0, 0.5, 0.0);
  glVertex2f(-0.5, -1.0);

  glColor3f(0.0, 0.5, 0.0);
  glVertex2f(-0.5, 1.0);

  glColor3f(0.0, 0.5, 0.0);
  glVertex2f(0.5, 1.0);

  glColor3f(0.0, 0.5, 0.0);
  glVertex2f(0.5, -1.0);

 glEnd();

glLineWidth(10.0f);
glColor3f(0.6, 0.1, 0.2);
 glBegin(GL_LINES);
  glVertex2f(0.4, -0.95);glVertex2f(0.3, 0.9);

 glEnd();

glPushMatrix();
glTranslatef(0.0f, 0.9f, 0.0f);

GLfloat theta;
GLfloat pi     = acos(-1.0);
GLfloat radius = 0.05f; 
GLfloat step   = 6.0f; 

glBegin(GL_TRIANGLE_FAN);
for(GLfloat a = 0.0f; a < 360.0f; a += step) {
    theta = 2.0f * pi * a / 180.0f;
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(radius * cos(theta), radius * sin(theta));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.2f, 0.5f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
for(GLfloat a = 0.0f; a < 360.0f; a += step) {
    theta = 2.0f * pi * a / 180.0f;
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(radius * cos(theta), radius * sin(theta));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f, 0.3f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
for(GLfloat a = 0.0f; a < 360.0f; a += step) {
    theta = 2.0f * pi * a / 180.0f;
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(radius * cos(theta), radius * sin(theta));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.1f, -0.3f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
for(GLfloat a = 0.0f; a < 360.0f; a += step) {
    theta = 2.0f * pi * a / 180.0f;
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(radius * cos(theta), radius * sin(theta));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.2f, -0.4f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
for(GLfloat a = 0.0f; a < 360.0f; a += step) {
    theta = 2.0f * pi * a / 180.0f;
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(radius * cos(theta), radius * sin(theta));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.3f, -0.2f, 0.0f);

glBegin(GL_TRIANGLE_FAN);
for(GLfloat a = 0.0f; a < 360.0f; a += step) {
    theta = 2.0f * pi * a / 180.0f;
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(radius * cos(theta), radius * sin(theta));
}
glEnd();
glPopMatrix();

 glutSwapBuffers();
}

int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowPosition(100, 100);
 glutInitWindowSize(800, 800);
 glutCreateWindow("table");

 glutDisplayFunc(display);
 glutMainLoop();

 return 0;
}
