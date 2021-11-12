#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cmath>

#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_H 600
#define WINDOW_W 400

void gl_init(int argc, char *argv[]);
void handler_draw();
void handler_input(unsigned char key, int x, int y);

int main(int argc, char *argv[]) {

	gl_init(argc, argv);

    return 0;
}

void gl_init(int argc, char *argv[]) {

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WINDOW_W, WINDOW_H);
    glutCreateWindow("ComS 336 HW 4 - Articulating Arm");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WINDOW_W/2, WINDOW_W/2, -WINDOW_W/2, WINDOW_W/2, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glutKeyboardFunc(handler_input);
	glutDisplayFunc(handler_draw);

    glutMainLoop();

	return;
}

void handler_draw() {

	glBegin(GL_POLYGON);

    glVertex2f (-.3,  -.3);
    glVertex2f(.3,  -.3);
    glVertex2f(.3, .3);
    glVertex2f( -.3, .3);

    glEnd();
    glFlush();

	return;
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
