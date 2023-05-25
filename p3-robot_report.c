/* List: p3-robot.c
 * Robot arm with two links and two joints.
 * Examination of world-local coordinates, modeling transfomation and
 * operation of matrix stack.
 */
#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

static int shoulder = 0, elbow = 0, thigh = 0, shin = 0;
static float theta = 0, rad = 0;

void myInit(char *progname)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(progname);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}



void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);




// 胴体
	glTranslated(0.0, 0.0, 0.0);
		glPushMatrix();
			glScaled(3.0, 4.0, 1.0);
			glutWireCube(1.0);
		glPopMatrix();




	glPushMatrix();
	// 右腕

		glPushMatrix();

			glTranslated(2.0, 2.0, 0.0);
			glPushMatrix();
				glScaled(0.0, 0.0, 0.0);
				glutWireCube(1.0);
			glPopMatrix();

			glRotated((double)shoulder, 1.0, 0.0, 0.0);
			glTranslated(0.0, -1.0, 0.0);
			glPushMatrix();
				glScaled(1.0, -2.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslated(0.0, -1.0,  0.0);
			glRotated((double)elbow, 1.0, 0.0, 0.0);
			glTranslated(0.0, -1.0, 0.0);
			glPushMatrix();
				glScaled(1.0, 2.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();

		// 左腕
		glPushMatrix();
			glTranslated(-2.0, 2.0, 0.0);
			glPushMatrix();
				glScaled(0.0, 0.0, 0.0);
				glutWireCube(1.0);
			glPopMatrix();

			glRotated((double)-shoulder, 1.0, 0.0, 0.0);
			glTranslated(0.0, -1.0, 0.0);
			glPushMatrix();
				glScaled(1.0, -2.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();


			glTranslated(0.0, -1.0, 0.0);
			glRotated((double)-elbow+180, 1.0, 0.0, 0.0);
			glTranslated(0.0, -1.0, 0.0);
			glPushMatrix();
				glScaled(1.0, 2.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();

		// 頭
		glPushMatrix();

			glTranslated(0.0, 3.0, 0.0);
			glPushMatrix();

				glutWireSphere(1.0,10, 10);

			glPopMatrix();
		glPopMatrix();




		// 左足
		glPushMatrix();
			glTranslated(1.0, -2.0, 0.0);
			glPushMatrix();
				glScaled(0.0, 0.0, 0.0);
				glutWireCube(1.0);
			glPopMatrix();

			glRotated((double)-thigh -30 , 1.0, 0.0, 0.0);

			glTranslated(0.0, -1.5, 0.0);
			glPushMatrix();
				glScaled(1.0, -3.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslated(0.0, -1.5, 0.0);
			glRotated((double)-shin , 1.0, 0.0, 0.0);
			glTranslated(0.0, -1.0, 0.0);
			glPushMatrix();
				glScaled(1.0, 2.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();

		// 右脚

		glPushMatrix();
			glTranslated(-1.0, -2.0, 0.0);
			glPushMatrix();
				glScaled(0.0, 0.0, 0.0);
				glutWireCube(1.0);
			glPopMatrix();

			glRotated((double)thigh -30, 1.0, 0.0, 0.0);

			glTranslated(0.0, -1.5, 0.0);
			glPushMatrix();
				glScaled(1.0, -3.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslated(0.0, -1.5, 0.0);
			glRotated((double)shin , 1.0, 0.0, 0.0);
			glTranslated(0.0, -1.0, 0.0);
			glPushMatrix();
				glScaled(1.0, 2.0, 1.0);
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();






	glPopMatrix();




	glutSwapBuffers();
}

void myReshape (int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)width/(double)height, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void myKeyboard (unsigned char key, int x, int y)
{
	switch (key) {
	// 	case 's':
	// 		shoulder = (shoulder + 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'S':
	// 		shoulder = (shoulder - 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'e':
	// 		elbow = (elbow + 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'E':
	// 		elbow = (elbow - 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'h':
	// 		thigh = (thigh + 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'H':
	// 		thigh = (thigh - 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'u':
	// 		shin = (shin + 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
	// 	case 'U':
	// 		shin = (shin - 5) % 360;
	// 		glutPostRedisplay();
	// 		break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}

}

void myIdle(void)
{

	theta = fmod(theta + 0.1, 360.0);
	rad = fmod(rad + 0.0002, 2.0);
	shoulder = sin(rad* M_PI )*60;

	elbow = -sin(rad* M_PI)*60-90;

	thigh = sin(rad* M_PI)*30 ;

	shin = -sin(rad* M_PI)*30 ;

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myInit(argv[0]);
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
