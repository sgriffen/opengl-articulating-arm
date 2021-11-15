#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cmath>

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define WINDOW_H 600
#define WINDOW_W 400

float xRotated, yRotated, zRotated;
GLUquadricObj *upperArm, *lowerArm, *hand;

void gl_init(int argc, char *argv[]);
void idle();
void reshape(int x, int y);
void handler_draw();
void handler_input(unsigned char key, int x, int y);

int main(int argc, char *argv[]) {

	gl_init(argc, argv);

    return 0;
}

void gl_init(int argc, char *argv[]) {
	xRotated = yRotated = zRotated = 30.0;

	glutInit(&argc, argv);
    //rglutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_W, WINDOW_H);
    glutCreateWindow("ComS 336 HW 4 - Articulating Arm");

	//glEnable(GL_DEPTH_TEST);
	//glOrtho(-WINDOW_W/2, WINDOW_W/2, -WINDOW_W/2, WINDOW_W/2, 1, -1);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//Setup arm
	upperArm = gluNewQuadric();
	gluQuadricDrawStyle(upperArm, GLU_LINE);

	lowerArm = gluNewQuadric();
	gluQuadricDrawStyle(lowerArm, GLU_LINE);

	hand = gluNewQuadric();
	gluQuadricDrawStyle(hand, GLU_LINE);

	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
    glutKeyboardFunc(handler_input);
	glutDisplayFunc(handler_draw);
    glutMainLoop();
	return;
}

void idle() {
	xRotated += 0.1;
	//yRotated += 0.1;
	zRotated += 0.1;
	handler_draw();
}

void reshape(int x, int y) {
	if(y == 0 || x == 0) return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(39.0, (GLdouble)x/(GLdouble)y, 0.6, 21.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,x,y);
}

void handler_draw() {
	glMatrixMode(GL_MODELVIEW);
	//clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glScalef(1.0,1.0,1.0);
	//gluCylinder(shape1, 10, 10, 5, 10, 10);
	//glutWire

	// glBegin(GL_POLYGON);
    // glVertex2f (-1,  -1);
    // glVertex2f(1,  -1);
    // glVertex2f(1, 1);
    // glVertex2f( -1, 1);
	// glEnd();

	
	gluCylinder(upperArm, .2, .2, 1.5, 20, 20);
	gluCylinder(lowerArm, .2, .2, 1.2, 20, 20);
	gluCylinder(hand, .2, .3, 0.5, 20, 20);

	gluPolygon


    glFlush();
	glutSwapBuffers();
}

void handler_input(unsigned char key, int x, int y) {
	switch(key) {
		case 'x': // Translate the arm in the world-space -x direction

			break;
		case 'X': // Translate the arm in the world-space +x direction

			break;
		case 'y': // Translate the arm in the world-space -y direction

			break;
		case 'Y': // Translate the arm in the world-space +y direction

			break;
		case 'z': // Translate the arm in the world-space -z direction

			break;
		case 'Z': // Translate the arm in the world-space +Z direction

			break;
		case 'u': // Rotate the arm at the shoulder about the upper arm's x axis in the positive direction

			break;
		case 'U': // Rotate the arm at the shoulder about the upper arm's x axis in the negative direction

			break;
		case 'v': // Rotate the arm at the shoulder about the upper arm's y axis in the positive direction

			break;
		case 'V': // Rotate the arm at the shoulder about the upper arm's y axis in the negative direction

			break;
		case 'w': // Rotate the arm at the shoulder about the upper arm's z axis in the positive direction

			break;
		case 'W': // Rotate the arm at the shoulder about the upper arm's z axis in the negative direction

			break;
		case 'c': // Curl the forearm at the elbow about the forearm's x axis in the positive direction

			break;
		case 'C': // Curl the forearm at the elbow about the forearm's x axis in the negative direction

			break;
		case 'r': // Rotate the forearm at the elbow about the forearm's z axis in the positive direction

			break;
		case 'R': // Rotate the forearm at the elbow about the forearm's z axis in the negative direction

			break;
		case 'p': // Pitch the hand at the wrist about the hand's x axis in the positive direction

			break;
		case 'P': // Pitch the hand at the wrist about the hand's x axis in the negative direction

			break;
		case 'a': // yAw the hand at the wrist about the hand's y axis in the positive direction

			break;
		case 'A': // yAw the hand at the wrist about the hand's y axis in the negative direction

			break;
		case 'o': // Toggle orthographic/perspective projection

			break;
	}

	return;
}
