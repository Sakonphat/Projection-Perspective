

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include "Affine.h"
#include <iomanip>
using namespace std;


// global data (ugh)
int width = 400, height = 200;
const char *name = "CS397 HW#2";


Point vertices[10] = { 
Point(8.0f, 0.0f, 50.0f), 
Point(8.0f, 10.0f, 50.0f),
Point(4.0f, 15.0f, 50.0f), 
Point(0.0f, 10.0f, 50.0f),
Point(0.0f, 0.0f, 50.0f),//4
Point(8.0f, 0.0f, 30.0f),
Point(0.0f, 0.0f, 30.0f),
Point(0.0f, 10.0f, 30.0f),
Point(4.0f, 15.0f, 30.0f),
Point(8.0f, 10.0f, 30.0f) 
};
int edges[17][2] = { {0,1},{1,2},{ 2,3 },{ 3,4 },{ 4,0 },{1,3},
{ 0,5 },{ 1,9 },{ 2,8 },{ 3,7 },{ 4,6 },{ 5,6 },{ 6,7 }, 
{ 7,8 },{ 8,9 },{ 9,5 },{9,7} };

int faces[16][3] = { {0,1,3},{ 0,3,4 },{ 1,2,3 },{ 5,9,1 },
{ 5,1,0 },{ 9,8,2 },{ 9,2,1 },{ 3,2,8 },{ 3,8,7 },{ 4,3,7 },
{ 4,7,6 },{ 0,5,6 },{ 0,6,4 },{ 5,9,7 },{5,7,6},{9,8,7} };



vector<Point> temp_verts(10);
const Point VRP(0, 0, 50);
const Vector VUP(0, 1, 0),
VPN(0, 0, 1);
float window[4] = { -1,9,-1,15 };
float L, R, bot, top, Near, Far;


void printHouseDat_from_temp_verts() {
	cout << "House Data" << endl;

	//printTemp_verts
	cout << temp_verts[0].x << " " << temp_verts[1].x << " " << temp_verts[2].x
		<< " " << temp_verts[3].x << " " << temp_verts[4].x << " " << temp_verts[5].x
		<< " " << temp_verts[6].x << " " << temp_verts[7].x << " " << temp_verts[8].x
		<< " " << temp_verts[9].x << endl;

	cout << temp_verts[0].y << " " << temp_verts[1].y << " " << temp_verts[2].y
		<< " " << temp_verts[3].y << " " << temp_verts[4].y << " " << temp_verts[5].y
		<< " " << temp_verts[6].y << " " << temp_verts[7].y << " " << temp_verts[8].y
		<< " " << temp_verts[9].y << endl;

	cout << temp_verts[0].z << " " << temp_verts[1].z << " " << temp_verts[2].z
		<< " " << temp_verts[3].z << " " << temp_verts[4].z << " " << temp_verts[5].z
		<< " " << temp_verts[6].z << " " << temp_verts[7].z << " " << temp_verts[8].z
		<< " " << temp_verts[9].z << endl;

	cout << temp_verts[0].w << " " << temp_verts[1].w << " " << temp_verts[2].w
		<< " " << temp_verts[3].w << " " << temp_verts[4].w << " " << temp_verts[5].w
		<< " " << temp_verts[6].w << " " << temp_verts[7].w << " " << temp_verts[8].w
		<< " " << temp_verts[9].w << endl;

	//printVertiecs
	//cout << vertices[0].x << " " << vertices[1].x << " " << vertices[2].x
	//	<< " " << vertices[3].x << " " << vertices[4].x << " " << vertices[5].x
	//	<< " " << vertices[6].x << " " << vertices[7].x << " " << vertices[8].x
	//	<< " " << vertices[9].x << endl;

	//cout << vertices[0].y << " " << vertices[1].y << " " << vertices[2].y
	//	<< " " << vertices[3].y << " " << vertices[4].y << " " << vertices[5].y
	//	<< " " << vertices[6].y << " " << vertices[7].y << " " << vertices[8].y
	//	<< " " << vertices[9].y << endl;

	//cout << vertices[0].z << " " << vertices[1].z << " " << vertices[2].z
	//	<< " " << vertices[3].z << " " << vertices[4].z << " " << vertices[5].z
	//	<< " " << vertices[6].z << " " << vertices[7].z << " " << vertices[8].z
	//	<< " " << vertices[9].z << endl;

	//cout << vertices[0].w << " " << vertices[1].w << " " << vertices[2].w
	//	<< " " << vertices[3].w << " " << vertices[4].w << " " << vertices[5].w
	//	<< " " << vertices[6].w << " " << vertices[7].w << " " << vertices[8].w
	//	<< " " << vertices[9].w << endl;
	cout << "---------------------------------------------------------------------------" << endl;
}
void printHouseDat_from_vertices() {
	cout << "House Data" << endl;

	//printVertiecs
	cout << vertices[0].x << " " << vertices[1].x << " " << vertices[2].x
		<< " " << vertices[3].x << " " << vertices[4].x << " " << vertices[5].x
		<< " " << vertices[6].x << " " << vertices[7].x << " " << vertices[8].x
		<< " " << vertices[9].x << endl;

	cout << vertices[0].y << " " << vertices[1].y << " " << vertices[2].y
		<< " " << vertices[3].y << " " << vertices[4].y << " " << vertices[5].y
		<< " " << vertices[6].y << " " << vertices[7].y << " " << vertices[8].y
		<< " " << vertices[9].y << endl;

	cout << vertices[0].z << " " << vertices[1].z << " " << vertices[2].z
		<< " " << vertices[3].z << " " << vertices[4].z << " " << vertices[5].z
		<< " " << vertices[6].z << " " << vertices[7].z << " " << vertices[8].z
		<< " " << vertices[9].z << endl;

	cout << vertices[0].w << " " << vertices[1].w << " " << vertices[2].w
		<< " " << vertices[3].w << " " << vertices[4].w << " " << vertices[5].w
		<< " " << vertices[6].w << " " << vertices[7].w << " " << vertices[8].w
		<< " " << vertices[9].w << endl;
	cout << "---------------------------------------------------------------------------" << endl;
}
void printAffine(Affine m) {
	for (int i = 0; i < 4; i++) {
		cout << m.row[i].x << " " << m.row[i].y << " " << m.row[i].z << " " << m.row[i].w << endl;
	}
	cout << "---------------------------------------------------------------------------" << endl;
}
void Projection_Perspective() {

	const Vector u(Cross(VUP, VPN).x, Cross(VUP, VPN).y, Cross(VUP, VPN).z),
				 v(Cross(VPN, u).x, Cross(VPN, u).y, Cross(VPN, u).z),
			     n(Cross(u, v).x, Cross(u, v).y, Cross(u, v).z);

	Point CW((window[0] + window[1]) / 2, (window[2] + window[3]) / 2, 0);
	Point PRP(4, 6, 30);
	Vector DOP((CW.x - PRP.x), (CW.y - PRP.y), (CW.z - PRP.z));

	//cout << "CW x= " << CW.x << " y= " << CW.y << " z= " << CW.z << endl;
	//cout << "PRP x= " << PRP.x << " y= " << PRP.y << " z= " << PRP.z << endl;
	//cout << "DOP x= " << DOP.x << " y= " << DOP.y << " z= " << DOP.z <<" w= "<< DOP.w << endl;

	Affine trans;
	Affine Rot;
	Affine temp;
	Affine shear;
	Affine scale;

	//Start N_per
	//Trans VRP to Origin and Rotate VRC
	//trans = Trans(-VRP);
	//Rot = WorldtoCam(u, v, n);
	//temp = Rot * trans;

	////Trans COP that is PRP to origin
	//trans = Trans(-PRP);
	//temp =  trans * temp;

	////Shear
	//shear = Shear( (-DOP.x) / DOP.z, (-DOP.y) / DOP.z);
	//temp = shear * temp;

	//Translate and scale into the perspective canonical view volume.
	// Scale per
	Point VRP_dat(-PRP.x, -PRP.y, -PRP.z);
	//cout << "VRP_dat x = " << VRP_dat.x << " y= " << VRP_dat.y << " z=" << VRP_dat.z << endl;
	float umin = window[0],
		umax = window[1],
		vmin = window[2],
		vmax = window[3],
		F = 1,
		B = -31;
	//cout << "umin = " << umin << endl;
	//cout << "umax = " << umax << endl;
	//cout << "vmin = " << vmin << endl;
	//cout << "vmax = " << vmax << endl;
	//cout << "B = " << B << endl;

	//scale = Scale( (2*VRP_dat.z)/((umax-umin)*(VRP_dat.z+B)),
	//				(2*VRP_dat.z)/((vmax-vmin)*(VRP_dat.z+B)),
	//				(-1)/(VRP_dat.z+B)  );
	//temp = scale * temp;

	//Multi with any points
	for (int i = 0; i < 10; i++) {
		vertices[i] = Scale((2 * VRP_dat.z) / ((umax - umin)*(VRP_dat.z + B)),
			(2 * VRP_dat.z) / ((vmax - vmin)*(VRP_dat.z + B)),
			(-1) / (VRP_dat.z + B)) * Shear((-DOP.x) / DOP.z, (-DOP.y) / DOP.z) * Trans(-PRP) * WorldtoCam(u, v, n) * Trans(-VRP) * vertices[i];
	}
	cout << "Finish N_per !!" << endl;
	printHouseDat_from_vertices();
	//End N_per


	//Mampping to Viewport
	float zmin = -1 * ((VRP_dat.z + F) / (VRP_dat.z + B));
	Affine m = Affine();
	m.row[0].x = 1;
	m.row[1].y = 1;
	m.row[2].z = (1) / (1 + zmin);
	m.row[2].w = (-zmin) / (1 + zmin);
	m.row[3].z = -1;
	m.row[3].w = 0;
	////cout << "zmin = " << zmin << endl;
	//temp = m * temp;
	//Affine mort( Vector(1,0,0), Vector(0, 1, 0), Vector(0, 0, 0), Point());
	//temp = mort * temp;
	//printAffine(temp);

	//3D view volume
	Vector T(1, 1, 1);
	//trans = Trans(T);
	//temp = trans * temp;
	//printAffine(temp);

	//Scale size 3D viewport
	float Xvmin = L,
		Xvmax = R,
		Yvmin = bot,
		Yvmax = top,
		Zvmin = Near,
		Zvmax = Far;
	//scale = Scale( (Xvmax-Xvmin)/2, (Yvmax-Yvmin)/2, (Zvmax-Zvmin)/1 );
	//temp = scale * temp;


	//trans = Trans(Vector(Xvmin,Yvmin,Zvmin));
	//temp = trans * temp;
	//printAffine(temp);
	
	Hcoords result[10];
	for (int i = 0; i < 10; i++) {
		result[i].x = ((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[0].x * vertices[i].x) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[0].y * vertices[i].y) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[0].z * vertices[i].z) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[0].w * vertices[i].w);

		result[i].y = ((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[1].x * vertices[i].x) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[1].y * vertices[i].y) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[1].z * vertices[i].z) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[1].w * vertices[i].w);

		result[i].z = ((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[2].x * vertices[i].x) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[2].y * vertices[i].y) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[2].z * vertices[i].z) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[2].w * vertices[i].w);

		result[i].w = ((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[3].x * vertices[i].x) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[3].y * vertices[i].y) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[3].z * vertices[i].z) +
			((Trans(Vector(Xvmin, Yvmin, Zvmin)) * Scale((Xvmax - Xvmin) / 2, (Yvmax - Yvmin) / 2, (Zvmax - Zvmin) / 1) * Trans(T) * Affine(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 0), Point()) * m).row[3].w * vertices[i].w);
	}
	
	
	//Divide by w
	for (int i = 0; i < 10; i++) {
		temp_verts[i].x = result[i].x / result[i].w;
		temp_verts[i].y = result[i].y / result[i].w;
		temp_verts[i].z = result[i].z / result[i].w;
		temp_verts[i].w = result[i].w / result[i].w;
		/*temp_verts[i] = result[i];*/
	}
	cout << "Finish Mapping Viewport !!" << endl;
	printHouseDat_from_temp_verts();
	//End Mapping 
	
	
}


void Init(void) {
	L = -200;
	R = 200;
	bot = -100;
	top = 100;
	Near = -100;
	Far = 100;
	glViewport(0, 0, width, height);
	Projection_Perspective();
	glOrtho(L, R, bot, top, Near, Far);
	
}


void Draw(void) {

	// clear the screen
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	 


	// draw rotating array of squares
	glColor3f(1 , 0, 0 );
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 16; i++) {
		Point& P = temp_verts[faces[i][0]],
			Q = temp_verts[faces[i][1]],
			R = temp_verts[faces[i][2]];
		glVertex3f(P.x,P.y,P.z);
		glVertex3f(Q.x, Q.y, Q.z);
		glVertex3f(R.x, R.y, R.z);
	}
	glEnd();

	//Draw the edges
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	for (int i = 0; i < 17; i++) {
		Point& P = temp_verts[edges[i][0]],
			Q = temp_verts[edges[i][1]];
		glVertex3f(P.x, P.y,P.z);
		glVertex3f(Q.x, Q.y,Q.z);
	}
	glEnd();
	glFlush();
	
	//glutSwapBuffers();
}





void Resized(int W, int H) {
	width = W;
	height = H;
}


void Loop(void) {
	glutPostRedisplay();
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 600);
	glutInitWindowSize(width, height);
	glutCreateWindow(name);
	glutDisplayFunc(Draw);
	glutReshapeFunc(Resized);
	glutIdleFunc(Loop);
	Init();
	glutMainLoop();
	return 0;
}
