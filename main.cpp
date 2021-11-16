// std includes
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cmath>

// opengl/glut includes
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// macros
#define WINDOW_H 720
#define WINDOW_W 960
#define OBJECT_RENDER_TYPE 0 // 0 to draw wireframe objects as wireframes, 1 to draw solid objects

// global vars
GLUquadricObj *upperArm, *lowerArm, *hand; // objects in the scene
bool projectionType = 0; // projection type of the scene (0 for perspective, 1 for orthographic)
GLenum g_drawStyle = GLU_LINE; // style to draw objects in
float g_xTranslated = 0.0, g_yTranslated = 0.0, g_zTranslated = -5.0; // global world-space translation offsets for all objects in scene
float g_xRotated = 0.0, g_yRotated = 0.0, g_zRotated = 0.0; // global world-space translation offsets for all objects in scene
float uarm_xRotated = 45.0; // upper arm rotation amount in it's relative x-axis
float uarm_yRotated = 45.0; // upper arm rotation amount in it's relative y-axis
float uarm_zRotated = 0.0; // upper arm rotation amount in it's relative z-axis
float larm_xRotated = 0.0; // lower arm "curl" amount at the point of attachment to the upper arm in it's relative x-axis
float larm_zRotated = 0.0; // lower arm "rotation" amount at the point of attachment to the upper arm in it's relative y-axis
float hand_xRotated = 0.0; // hand "pitch" amount at the point of attachment to the lower arm in it's relative x-axis
float hand_yRotated = 0.0; // hand "yaw" amount at the point of attachment to the lower arm in it's relative y-axis

// function defs
void gl_init(int argc, char *argv[]);
void scene_init();
void handler_idle();
void handler_reshape(int x, int y);
void handler_draw();
void handler_input(unsigned char key, int x, int y);
void handler_camera(int winW, int winH);
void draw_cylinder(GLUquadricObj *obj, GLdouble radiusB, GLdouble radiusT, GLdouble height, GLfloat colorR = 1.0, GLfloat colorG = 1.0, GLfloat colorB = 1.0, GLint slices = 20, GLint stacks = 20, GLenum style = g_drawStyle);

int main(int argc, char *argv[]) {

	scene_init();
	gl_init(argc, argv);

    return 0;
}

void gl_init(int argc, char *argv[]) {
	g_xRotated = g_yRotated = g_zRotated = 30.0;

	glutInit(&argc, argv);
    //rglutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_W, WINDOW_H);
    glutCreateWindow("ComS 336 HW 4 - Articulating Arm - Projection");

	glutIdleFunc(handler_idle);
	glutReshapeFunc(handler_reshape);
    glutKeyboardFunc(handler_input);
	glutDisplayFunc(handler_draw);



    glutMainLoop();
}

void scene_init() {
	upperArm = gluNewQuadric(); // add new object to scene
	lowerArm = gluNewQuadric(); // add new object to scene
	hand = gluNewQuadric(); // add new object to scene
}

void handler_idle() {
	g_xRotated += 0.1;
	//g_yRotated += 0.1;
	g_zRotated += 0.1;
	handler_draw();
}

void handler_reshape(int winW, int winH) {
	if (!winW || !winH) { return; }
	handler_camera(winW, winH);
}

void handler_camera(int winW, int winH) {
	glViewport(0,0,winW,winH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (projectionType) {
		// 2d orthographic projection mode
		glOrtho(-1.5*(GLfloat)winW/(GLfloat)winH, 1.5*(GLfloat)winW/(GLfloat)winH, -1.5, 1.5, 0.6, 21.0);
	} else {
		// 3d perspective projection mode
		gluPerspective(39.0, (GLdouble)winW/(GLdouble)winH, 0.6, 21.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// gluLookAt(); // Move and point the camera to a different spot
}

void handler_draw() {

	int winW = glutGet(GLUT_WINDOW_WIDTH);
	int winH = glutGet(GLUT_WINDOW_HEIGHT);

	handler_camera(winW, winH);

	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window

	// apply global transforms to all objects in scene
	glLoadIdentity();
	glTranslated(-1.5, 1.0, 0.0);
	glTranslatef(g_xTranslated,g_yTranslated,g_zTranslated); // global world-space translation on all objects in scene
	//glRotatef(g_xRotated, 1.0, 0.0, 0.0); // global world-space x-axis rotation offset on all objects in scene
	//glRotatef(g_yRotated, 0.0, 1.0, 0.0); // global world-space y-axis rotation offset on all objects in scene
	//glRotatef(g_zRotated, 0.0, 0.0, 1.0); // global world-space z-axis rotation offset on all objects in scene
	glScalef(1.0,1.0,1.0);

	// draw upper arm with rotation and position offsets
	glRotatef(uarm_xRotated, 1.0, 0.0, 0.0);
	glRotatef(uarm_yRotated, 0.0, 1.0, 0.0);
	glRotatef(uarm_zRotated, 0.0, 0.0, 1.0);
	draw_cylinder(upperArm, 0.1, 0.1, 1.5, 1.0, 0.0, 0.0, 20, 20, GLU_FILL);

	// draw lower arm with rotation and position offsets
	glTranslated(0.0, 0.0, 1.5);
	//glRotatef(90.0, 0.0, 0.0, 1.0); // fix orientation so curl is "side-to-side" relative to camera position
	glRotatef(larm_xRotated, 1.0, 0.0, 0.0);
	glRotatef(larm_zRotated, 0.0, 0.0, 1.0);
	draw_cylinder(lowerArm, 0.1, 0.1, 1.0, 0.0, 1.0, 0.0, 20, 20, GLU_FILL);

	// draw hand with rotation and position offsets
	glTranslated(0.0, 0.0, 1.0);
	//glRotatef(90.0, 0.0, 0.0, 1.0); // fix orientation so pitch is "up-and-down" and yaw is "side-to-side" relative to camera position
	glRotatef(hand_xRotated, 1.0, 0.0, 0.0);
	glRotatef(hand_yRotated, 0.0, 1.0, 0.0);
	draw_cylinder(hand, 0.1, 0.15, 0.5, 0.0, 0.0, 1.0, 20, 20, GLU_FILL);

    glFlush();
	glutSwapBuffers();
}

void handler_input(unsigned char key, int x, int y) {
	switch(key) {
		case 'x': // translate the arm in the world-space -x direction
			g_xTranslated -= 0.01;
			break;
		case 'X': // translate the arm in the world-space +x direction
			g_xTranslated += 0.01;
			break;
		case 'y': // translate the arm in the world-space -y direction
			g_yTranslated -= 0.01;
			break;
		case 'Y': // translate the arm in the world-space +y direction
			g_yTranslated += 0.01;
			break;
		case 'z': // translate the arm in the world-space -z direction
			g_zTranslated -= 0.05;
			break;
		case 'Z': // translate the arm in the world-space +Z direction
			g_zTranslated += 0.05;
			break;
		case 'u': // rotate the arm at the shoulder about the upper arm's x axis in the positive direction
			uarm_xRotated += 0.5;
			break;
		case 'U': // rotate the arm at the shoulder about the upper arm's x axis in the negative direction
			uarm_xRotated -= 0.5;
			break;
		case 'v': // rotate the arm at the shoulder about the upper arm's y axis in the positive direction
			uarm_yRotated += 0.5;
			break;
		case 'V': // rotate the arm at the shoulder about the upper arm's y axis in the negative direction
			uarm_yRotated -= 0.5;
			break;
		case 'w': // rotate the arm at the shoulder about the upper arm's z axis in the positive direction
			uarm_zRotated += 1.0;
			break;
		case 'W': // rotate the arm at the shoulder about the upper arm's z axis in the negative direction
			uarm_zRotated -= 1.0;
			break;
		case 'c': // curl the forearm at the elbow about the forearm's x axis in the positive direction
			larm_xRotated += 0.5;
			break;
		case 'C': // curl the forearm at the elbow about the forearm's x axis in the negative direction
			larm_xRotated -= 0.5;
			break;
		case 'r': // rotate the forearm at the elbow about the forearm's z axis in the positive direction
			larm_zRotated += 1.0;
			break;
		case 'R': // rotate the forearm at the elbow about the forearm's z axis in the negative direction
			larm_zRotated -= 1.0;
			break;
		case 'p': // pitch the hand at the wrist about the hand's x axis in the positive direction
			hand_xRotated += 0.5;
			break;
		case 'P': // pitch the hand at the wrist about the hand's x axis in the negative direction
			hand_xRotated -= 0.5;
			break;
		case 'a': // yaw the hand at the wrist about the hand's y axis in the positive direction
			hand_yRotated += 0.5;
			break;
		case 'A': // yaw the hand at the wrist about the hand's y axis in the negative direction
			hand_yRotated -= 0.5;
			break;
		case 'o': // toggle orthographic/perspective projection
			projectionType = !projectionType;
			if(projectionType)
				glutSetWindowTitle("ComS 336 HW 4 - Articulating Arm - Orthographic");
			else
				glutSetWindowTitle("ComS 336 HW 4 - Articulating Arm - Projection");
			break;
		case 32: // space bar
			// change draw style
			if (g_drawStyle == GLU_FILL) { g_drawStyle = GLU_LINE; }
			else if (g_drawStyle == GLU_LINE) { g_drawStyle = GLU_SILHOUETTE; }
			else if (g_drawStyle == GLU_SILHOUETTE) { g_drawStyle = GLU_POINT; }
			else { g_drawStyle = GLU_FILL; }
			break;
		case 27: // escape key
			// exit program
			exit(0);
			break;
	}
}

void draw_cylinder(GLUquadricObj *obj, GLdouble radiusB, GLdouble radiusT, GLdouble height, GLfloat colorR, GLfloat colorG, GLfloat colorB, GLint slices, GLint stacks, GLenum style) {

	glColor3f(colorR, colorG, colorB); // set color
	gluQuadricDrawStyle(obj, style); // set draw style
	gluCylinder(obj, radiusB, radiusT, height, slices, stacks); //draw cylinder

	glPushMatrix(); // save current state
	// draw top cap of cylinder
	glTranslated(0.0, 0.0, height);
	gluDisk(obj, 0.0, radiusT, slices, stacks);
	glPopMatrix(); // restore previous state

	glPushMatrix(); // save current state
	// draw bottom cap of cylinder
	glRotated(180.0, 1.0, 0.0, 0.0);
	gluDisk(obj, 0.0, radiusB, slices, stacks);
	glPopMatrix(); // restore previous state
}
