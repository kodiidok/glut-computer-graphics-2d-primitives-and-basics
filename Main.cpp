
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int WINDOW_WIDTH = 720;
int WINDOW_HEIGHT = 480;

float sq_pos[] = { 0.0f, 0.0f };
float sq_rot = 0.0f;
float sq_scl = 1.0f;

const float pi = 3.14;

char keyPressedLabel[20] = ""; // Label to store the pressed key information

void renderBitmapString(float x, float y, void* font, const char* string) {
	glRasterPos2f(x, y);
	while (*string) {
		glutBitmapCharacter(font, *string);
		string++;
	}
}

void displayLabel() {
	glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
	renderBitmapString(-9.0f, 9.0f, GLUT_BITMAP_HELVETICA_12, "Key Pressed:");
	renderBitmapString(-9.0f, 8.5f, GLUT_BITMAP_HELVETICA_12, keyPressedLabel);
}

void square() {
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f); // green
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
}

void circle(float radius, int segments) {
	glColor3f(0.0f, 1.0f, 0.0f); // green

	float degree = 360 / segments; // angle of a sector

	float x = 0.0f;
	float y = 0.0f;

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < segments; i++) {
		float angle = i * degree * (pi / 180.0f); // Convert degree to radians
		x = radius * cos(angle);
		y = radius * sin(angle);
		printf("(%f, %f)\n", x, y);
		glVertex2f(x, y);
	}
	glEnd();

}

void axes() {
	// x axis
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); // red
	glVertex2f(-10.0f, 0.0f);
	glVertex2f(10.0f, 0.0f);
	glEnd();

	// y axis
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f); // blue
	glVertex2f(0.0f, 10.0f);
	glVertex2f(0.0f, -10.0f);
	glEnd();
}

void spin_sq(int value) {
	sq_rot += 15.0f;
	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	axes();

	// LOCAL >> T -> R -> S
	// GLOABAL >> S -> R -> T

	// animate using timer
	glutTimerFunc(1000 / 60, spin_sq, 0);

	// control using keyboard functions
	glPushMatrix();
	glTranslatef(sq_pos[0], sq_pos[1], 0.0f);
	glRotatef(sq_rot, 0.0f, 0.0f, 1.0f);
	glScalef(sq_scl, sq_scl, 0.0f);
	square();
	glPopMatrix();

	glPopMatrix();

	// Display the label with the pressed key information
	displayLabel();

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);

	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	// w = aspect_ratio * h
	// h = w / aspect_ratio

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		gluOrtho2D(-10, 10, -10 / aspect_ratio, 10 / aspect_ratio);
	}
	else {
		gluOrtho2D(-10 * aspect_ratio, 10 * aspect_ratio, -10, 10);
	}
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		sq_scl += 0.5f;
		snprintf(keyPressedLabel, sizeof(keyPressedLabel), "Up Arrow: Scale Up");
	}
	if (key == GLUT_KEY_DOWN) {
		sq_scl -= 0.5f;
		snprintf(keyPressedLabel, sizeof(keyPressedLabel), "Down Arrow: Scale Down");
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	// movement

	if (key == 'w') { // up
		sq_pos[1] += 0.5f;
		snprintf(keyPressedLabel, sizeof(keyPressedLabel), "W: Move Up");
	}
	if (key == 'a') { // left
		sq_pos[0] -= 0.5f;
		snprintf(keyPressedLabel, sizeof(keyPressedLabel), "A: Move Left");
	}
	if (key == 's') { // down
		sq_pos[1] -= 0.5f;
		snprintf(keyPressedLabel, sizeof(keyPressedLabel), "S: Move Down");
	}
	if (key == 'd') { // right
		sq_pos[0] += 0.5f;
		snprintf(keyPressedLabel, sizeof(keyPressedLabel), "D: Move Right");
	}

	glutPostRedisplay();
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2D Graphics Template");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutSpecialFunc(keyboardSpecial);
	glutKeyboardFunc(keyboard);

	init();
	glutMainLoop();

	return 0;
}