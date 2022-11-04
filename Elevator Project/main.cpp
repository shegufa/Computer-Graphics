///header files
#include<stdio.h>
#include <windows.h>
#include <GL/glut.h>

///macro
#define MAX_FLOOR 9
#define LIFT_HEIGHT 24
#define LIFT_WIDTH 20
#define LIFT_STEP 0.05

double initPos = LIFT_HEIGHT / 2.0 * MAX_FLOOR * -1;
double liftPos = initPos;

///building width and height
double bw = LIFT_WIDTH * 10;
double bh = LIFT_HEIGHT * (MAX_FLOOR + 1);

///building left,right,down,top
double bl = -bw / 2.0;
double br = bw / 2.0;
double bd = -bh / 2.0;
double bt = bh / 2.0;

///lift ...
double ll = -LIFT_WIDTH / 2.0;
double lr = LIFT_WIDTH / 2.0;
double ld = -LIFT_HEIGHT / 2.0;
double lt = LIFT_HEIGHT / 2.0;

int curr_floor = 0;
int flag = 0;
void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}
void drawstring(char string[],float x1,float y1,float z1)
{
    int i,j;
	j=strlen(string);
	glRasterPos3f(x1,y1,z1);
	for (i=0;i<j;i++)
	{
        glutBitmapCharacter(currentfont, string[i]);
	}
}
void screen1()
{
    glClearColor(0,0,0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0,1.0,1.0);
    char str1[]="Rajshahi University of Engineering and Technology";
    drawstring(str1,bl-40,bt+30,0.0);
    char str2[]="Project on Computer Graphics and Animation";
    drawstring(str2,bl-30,bt-10,0.0);

    char str3[]="Presented by:";
    drawstring(str3,bl-20,(bt+bd)/2.0 + 30,0.0);
    char str4[]="Shegufa Rob";
    drawstring(str4,bl,(bt+bd)/2.0,0.0);
    char str5[]="1603001";
    drawstring(str5,bl,(bt+bd)/2.0 - 20,0.0);
    char str6[]="Press Space to Continue";
    drawstring(str6,bl-20,bd-20,0.0);
    glFlush();
}
void screen3()
{
    glClearColor(0,0,0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0,1.0,1.0);
    char str1[]="Thank you.";
    drawstring(str1,-50.0,0.9,0.0);
    glFlush();
}


void drawQuad(double l, double d, double r, double u, bool isSolid = false)
{
    isSolid ? glBegin(GL_QUADS) : glBegin(GL_LINES); {
		glVertex2f(l, d);
		glVertex2f(l, u);

		glVertex2f(l, u);
		glVertex2f(r, u);

		glVertex2f(r, u);
		glVertex2f(r, d);

		glVertex2f(r, d);
		glVertex2f(l, d);
	}glEnd();
}


void drawObjects()
{
    glColor3f(1,1,1);
    drawQuad(bl, bd, br, bt);

    double textPos = bd + LIFT_HEIGHT / 4.0;
    char *string = "0123456789";
    for (int i = 0; i <= MAX_FLOOR; i++) {
        glColor3f(1,0,1);
        glBegin(GL_LINES); {
            glVertex2f(bl, bd + i * LIFT_HEIGHT);
            glVertex2f(br, bd + i * LIFT_HEIGHT);
        } glEnd();

        glRasterPos2f(-LIFT_WIDTH / 8.0, textPos);
        glColor3f (1.0, 0.0, 0.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
        textPos += LIFT_HEIGHT;
    }

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0,1.0,1.0);
    char str1[]="Which floor do you want to go?";
    drawstring(str1,bl-20,bt+20,0.0);
    char str2[]="Press q to quit";
    drawstring(str2,bl,bd-20,0.0);

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0, liftPos, 0);
    drawQuad(ll, ld, lr, lt, true);
    glPopMatrix();
}


void keyboardListener(unsigned char key, int x,int y)
{
	if(key >= '0' && key <= '0' + MAX_FLOOR) {
        curr_floor = key - '0';
	}
	if(key == ' '){
        flag = 1;
	}
	if(key == 'q'){
        flag = 2;
	}
}


void specialKeyListener(int key, int x,int y)
{
	switch(key){
		case GLUT_KEY_DOWN:		/// down arrow key
            if (curr_floor > 0) {
                curr_floor--;
            }
			break;
		case GLUT_KEY_UP:		/// up arrow key
            if (curr_floor < MAX_FLOOR) {
                curr_floor++;
            }
			break;
		default:
			break;
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,200,	0,0,0,	0,1,0);
	glMatrixMode(GL_MODELVIEW);
    if(flag==0)
        screen1();
    else if(flag==1){
       drawObjects();
    }
    else{
        screen3();
    }
	glutSwapBuffers();
}



void animate()
{
    if(initPos + curr_floor * LIFT_HEIGHT > liftPos) {
        liftPos += LIFT_STEP;
    }
    if(initPos + curr_floor * LIFT_HEIGHT < liftPos) {
        liftPos -= LIFT_STEP;
    }

	glutPostRedisplay();
}

void init()
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80,	1,	1,	0.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("A simple elevator simulation");

	init();

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutIdleFunc(animate);

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	glutMainLoop();

	return 0;
}

