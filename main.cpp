#include <GL/glut.h>
#include <iostream>
#include "A_asterisco.h"
#include "BlockNodeFunctions.h"

using namespace std;


vector<BlockNode> res;
BlockNode actual;
BlockNode final;
int iteracion=0;



using namespace std;
GLfloat xRotated[15], yRotated[15], zRotated[15];

int window_2, window_1;
int blocks=0;
int torres=0;

GLfloat matrixP[5][5] =
{
	{1,2,3,4,5},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	//{7,0,0,0,0,0,0},
	//{0,0,0,0,0,0,0},
};
GLfloat matrix[5][5] =
{
	{1,0,0,0,0},
	{2,3,4,0,0},
	{0,0,0,0,0},
	{5,0,0,0,0},
	{0,0,0,0,0},
	//{7,0,0,0,0,0,0},
	//{0,0,0,0,0,0,0},
};


GLfloat color[15][3] =
{
	{0.0,0.0,0.5},
	{0.0,0.0,1.0},
	{0.0,0.5,0.0},
	{0.0,1.0,0.0},
	{0.5,0.0,0.0},
	{1.0,0.0,0.0},
	{0.0,1.0,1.0},
	{1.0,0.0,1.0},
	{1.0,1.0,0.0},
	{0.5,1.0,0.0},
	{0.0,1.0,0.5},
	{1.0,0.5,0.0},
	{1.0,0.0,0.5},
	{1.0,0.5,0.5},
	{1.0,1.0,1.0},
};


void init(void)
{
glClearColor(0,0,0,0);
 
}

void DrawCube(float x, float y, float z, float tam,int id)
{

    //glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    //glClear(GL_COLOR_BUFFER_BIT);
   	//glLoadIdentity();
    //glTranslatef(0.0,0.0,-10.5);
    //glRotatef(xRotated[id],1.0,0.0,0.0);
    // rotation about Y axis
    //glRotatef(yRotated[id],0.0,1.0,0.0);
    // rotation about Z axis
    //glRotatef(zRotated[id],0.0,0.0,1.0);
  glBegin(GL_QUADS);        // Draw The Cube Using quads
    glColor3fv(color[id]);    // Color Blue
    glVertex3f( (tam/2)+x, (tam/2)+y,-(tam/2)+z);    // Top Right Of The Quad (Top)
    glVertex3f(-(tam/2)+x, (tam/2)+y,-(tam/2)+z);    // Top Left Of The Quad (Top)
    glVertex3f(-(tam/2)+x, (tam/2)+y, (tam/2)+z);    // Bottom Left Of The Quad (Top)
    glVertex3f( (tam/2)+x, (tam/2)+y, (tam/2)+z);    // Bottom Right Of The Quad (Top)
    //glColor3f(2.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( (tam/2)+x,-(tam/2)+y, (tam/2)+z);    // Top Right Of The Quad (Bottom)
    glVertex3f(-(tam/2)+x,-(tam/2)+y, (tam/2)+z);    // Top Left Of The Quad (Bottom)
    glVertex3f(-(tam/2)+x,-(tam/2)+y,-(tam/2)+z);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( (tam/2)+x,-(tam/2)+y,-(tam/2)+z);    // Bottom Right Of The Quad (Bottom)
    //glColor3f((tam/2),0.0f,0.0f);    // Color Red    
    glVertex3f( (tam/2)+x, (tam/2)+y, (tam/2)+z);    // Top Right Of The Quad (Front)
    glVertex3f(-(tam/2)+x, (tam/2)+y, (tam/2)+z);    // Top Left Of The Quad (Front)
    glVertex3f(-(tam/2)+x,-(tam/2)+y, (tam/2)+z);    // Bottom Left Of The Quad (Front)
    glVertex3f( (tam/2)+x,-(tam/2)+y, (tam/2)+z);    // Bottom Right Of The Quad (Front)
    //glColor3f((tam/2),(tam/2),0.0f);    // Color Yellow
    glVertex3f( (tam/2)+x,-(tam/2)+y,-(tam/2)+z);    // Top Right Of The Quad (Back)
    glVertex3f(-(tam/2)+x,-(tam/2)+y,-(tam/2)+z);    // Top Left Of The Quad (Back)
    glVertex3f(-(tam/2)+x, (tam/2)+y,-(tam/2)+z);    // Bottom Left Of The Quad (Back)
    glVertex3f( (tam/2)+x, (tam/2)+y,-(tam/2)+z);    // Bottom Right Of The Quad (Back)
    //glColor3f(0.0f,0.0f,(tam/2));    // Color Blue
    glVertex3f(-(tam/2)+x, (tam/2)+y, (tam/2)+z);    // Top Right Of The Quad (Left)
    glVertex3f(-(tam/2)+x, (tam/2)+y,-(tam/2)+z);    // Top Left Of The Quad (Left)
    glVertex3f(-(tam/2)+x,-(tam/2)+y,-(tam/2)+z);    // Bottom Left Of The Quad (Left)
    glVertex3f(-(tam/2)+x,-(tam/2)+y, (tam/2)+z);    // Bottom Right Of The Quad (Left)
    //glColor3f((tam/2),0.0f,(tam/2));    // Color Violet
    glVertex3f( (tam/2)+x, (tam/2)+y,-(tam/2)+z);    // Top Right Of The Quad (Right)
    glVertex3f( (tam/2)+x, (tam/2)+y, (tam/2)+z);    // Top Left Of The Quad (Right)
    glVertex3f( (tam/2)+x,-(tam/2)+y, (tam/2)+z);    // Bottom Left Of The Quad (Right)
    glVertex3f( (tam/2)+x,-(tam/2)+y,-(tam/2)+z);    // Bottom Right Of The Quad (Right)
  glEnd();            // End Drawing The Cube
glFlush();
}

double rotate_y = 0;
double rotate_x = 0;

double rotate_y2 = 0;
double rotate_x2 = 0;

void specialKeys(int key, int x, int y){
	if(key == GLUT_KEY_RIGHT){
		actual=res[iteracion];
		iteracion++;
		cout<<iteracion<<endl;
		if (iteracion<0)
		{
			iteracion=0;
		}
		if (iteracion>res.size()-1)
		{
			iteracion=res.size()-1;
		}
	} //rotate_y += 5;
	else if(key == GLUT_KEY_LEFT){
		actual=res[iteracion];
		iteracion--;
		cout<<iteracion<<endl;
		if (iteracion<0)
		{
			iteracion=0;
		}
		if (iteracion>res.size()-1)
		{
			iteracion=res.size()-1;
		}
	} //rotate_y -=5;
	else if(key == GLUT_KEY_UP) rotate_y +=5;
	else if(key == GLUT_KEY_DOWN) rotate_y -= 5;
	glutPostRedisplay();
}

void specialKeys2(int key, int x, int y){
	if(key == GLUT_KEY_RIGHT) rotate_y2 += 5;
	else if(key == GLUT_KEY_LEFT) rotate_y2 -=5;
	//else if(key == GLUT_KEY_UP) rotate_x +=5;
	//else if(key == GLUT_KEY_DOWN) rotate_x -= 5;
	glutPostRedisplay();
}

void display_1(){
	float tam=5;
	//int prueba=0;
	for (int i = 0; i < actual.numOfBlocks; ++i)
	{
		tam=tam*0.8;
	}
	
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(60, w/h, 0.1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(9,3,0,
			  -5,0,5.5,
			  0,0,5);
	//glRotatef(rotate_x, 1.0, 0.0, 0.0);
	//glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	//int id=0;
	float y_ini=-4;
	float z_ini=0;
	/*for(auto iter = actual.torres.begin(); iter != actual.torres.end(); ++iter){
        for(auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2){
            cout<<iter2->id<<" ";
        }
        cout<<endl;
	}*/
	for (int i = 0; i < (actual.torres).size(); ++i)
	{
		for (int j = 0; j < (actual.torres[i]).size(); ++j)
		{
			if (actual.torres[i][j].id!=0)
			{
				DrawCube(0,y_ini+(i*tam+1),z_ini+(j*tam),tam,actual.torres[i][j].id);
				//id++;
			}
		}
	}
	
	//DrawCube(0,-3,0,0.5,1);
	//DrawCube(0,-3,0.5,0.5,2);
	
	//cout<<prueba<<endl;
	glutSwapBuffers();
}

void display_2(){

	float tam=5;
	//int prueba=0;
	for (int i = 0; i < actual.numOfBlocks; ++i)
	{
		tam=tam*0.8;
	}
	
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(60, w/h, 0.1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(9,3,0,
			  -5,0,5.5,
			  0,0,5);
	//glRotatef(rotate_x, 1.0, 0.0, 0.0);
	//glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_x2, 1.0, 0.0, 0.0);
	glRotatef(rotate_y2, 0.0, 1.0, 0.0);
	//int id=0;
	float y_ini=-4;
	float z_ini=0;
	for (int i = 0; i < (final.torres).size(); ++i)
	{
		for (int j = 0; j < (final.torres[i]).size(); ++j)
		{
			if (final.torres[i][j].id!=0)
			{
				DrawCube(0,y_ini+(i*tam+1),z_ini+(j*tam),tam,final.torres[i][j].id);
				//id++;
			}
		}
	}
	
	//DrawCube(0,-3,0,0.5,1);
	//DrawCube(0,-3,0.5,0.5,2);

	glutSwapBuffers();
}

/*void animation(int id)
{
 
     yRotated[id] += 0.01;
     xRotated[id] += 0.02;
    DrawCube(0.0, 0.0, 0.0, 0.0,0);
}*/


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

int main(int argc, char** argv){

if(argc != 3){
        cout<<"Faltan argumentos <fileOfInitBlock> <fileOfGoalBlock>"<<endl;
        return 1;
    }
    string fileOfInitBlockName(argv[1]);
    string fileOfGoalBlockName(argv[2]);
    BlockNode initBlock(fileOfInitBlockName);
    BlockNode goalBlock(fileOfGoalBlockName);
    if(initBlock.numOfBlocks != goalBlock.numOfBlocks){
        cout<<"El número de bloques entre el inicial y el final no coincide"<<endl;
        return 2;
    }
    if(initBlock.torres.size() != goalBlock.torres.size()){
        cout<<"El número de torres entre el inicial y el final no coincide"<<endl;
        return 3;
    }
    goalNode = goalBlock;
    A_Asterisco<BlockNode> Aa(heuristic, createSons, heapCompare, hashFun, hashCompare);
    res = Aa.start(initBlock, 0);
    actual=res[iteracion];
    final=res[res.size()-1];

    cout<<endl<<endl;
    cout<<"--------Solución-------"<<endl;

    for(BlockNode node : res){
        cout<<endl;
        node.print();
        cout<<endl;
    }
    
  //  return 0;


glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
glutInitWindowSize(640, 480);
glutInitWindowPosition(0, 0);
//glutCreateWindow(argv[0]);

window_1= glutCreateWindow ("s");
glutSetWindowTitle("BLOQUES DESORDENADOS");
init();
glutDisplayFunc(display_1);
glutSpecialFunc(specialKeys);
window_2 = glutCreateWindow ("s2");
glutSetWindowTitle("SOLUCION A ALCANZAR");
init ();
glutDisplayFunc(display_2);
//glutSpecialFunc(specialKeys2);
   //glutReshapeFunc(reshape_2);
//glutReshapeFunc(reshape);
//Set the function for the animation.
//glutIdleFunc(animation);
glutMainLoop();
return 0;
}