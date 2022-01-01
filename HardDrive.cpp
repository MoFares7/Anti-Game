#include "HardDrive.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <cmath>
#include "texture.h"		// Header File For Texture Loader (only bmp files supported)
#include "3DTexture.h"		// Header File For Model Texture Binding (only bmp files are supported)
#include "Model_3DS.h"

int SKYFRONT, SKYBACK, SKYRIGHT, SKYLEFT, SKYUP, SKYDOWN;
int Image;
int Image1;
int Image2;
int Image3;
int cpu1;
int ram1;
int r;


HardDrive::HardDrive()
{
	///hardModel = new Hard();
	SKYRIGHT = LoadTexture("Resources/Textures/ice.bmp");
	SKYLEFT = LoadTexture("Resources/Textures/ice.bmp");
	SKYFRONT = LoadTexture("Resources/Textures/ice.bmp");
	SKYBACK = LoadTexture("Resources/Textures/ice.bmp");
	SKYUP = LoadTexture("Resources/Textures/ice.bmp");
	SKYDOWN = LoadTexture("Resources/Textures/hardd.bmp");


	Image = LoadTexture("Resources/Textures/ground.bmp");

	Image1 = LoadTexture("Resources/Textures/pro.bmp");

	Image2 = LoadTexture("Resources/Textures/black.bmp");

	Image3 = LoadTexture("Resources/Textures/gold.bmp");

	cpu1 = LoadTexture("Resources/Textures/cpu.bmp");

	ram1 = LoadTexture("Resources/Textures/ram.bmp");

	r = LoadTexture("Resources/Textures/r.bmp");

}


float hardbody(float x, float y, float z, float width, float height, float length) {


	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SKYFRONT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SKYLEFT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SKYUP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SKYDOWN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	return 0;
}

void  DownQuads() {

	//Main Circular
	glBindTexture(GL_TEXTURE_2D, Image);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-5, -2.2, 10);
	glTexCoord2d(0, 1);
	glVertex3d(5, -2.2, 10);
	glTexCoord2d(1, 0);
	glVertex3d(5, -2.2, -10);
	glTexCoord2d(1, 1);
	glVertex3d(-5, -2.2, -10);
	glEnd();




}

void  UpQuads() {
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-5, 2.2, 7);
	glTexCoord2d(0, 1);
	glVertex3d(5, 2.2, 7);
	glTexCoord2d(1, 0);
	glVertex3d(5, 2.2, -9.5);
	glTexCoord2d(1, 1);
	glVertex3d(-5, 2.2, -9.5);

	glEnd();
}

void QuadsCollected1() {
	glBindTexture(GL_TEXTURE_2D, Image2);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glTexCoord2d(1, 0);
	glVertex3d(0, -2.2, -1);
	glTexCoord2d(1, 1);
	glVertex3d(-1, -2.2, -1);

	glEnd();

}

void QuadsCollected2() {

	glBindTexture(GL_TEXTURE_2D, Image2);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glVertex3d(0, -1.7, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-1, -1.7, 0);
	glTexCoord2d(1, 1);


	glEnd();
}

void QuadsCpu1() {
	glBindTexture(GL_TEXTURE_2D, cpu1);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(1, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(1, -2.2, -2);
	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, -2);

	glEnd();

}

void QuadsCpu2() {

	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(1, -2.2, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1, -2, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-1, -2, 0);

	glEnd();
}

void QuadsRam1() {
	glBindTexture(GL_TEXTURE_2D, ram1);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glTexCoord2d(1, 0);
	glVertex3d(0, -2.2, -1);
	glTexCoord2d(1, 1);
	glVertex3d(-1, -2.2, -1);

	glEnd();
}

void QuadsRam2() {

	glBindTexture(GL_TEXTURE_2D, Image3);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glVertex3d(0, -1.9, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-1, -1.9, 0);
	glTexCoord2d(1, 1);


	glEnd();
}

void QuadsIc1() {
	glBindTexture(GL_TEXTURE_2D, Image2);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glTexCoord2d(1, 0);
	glVertex3d(0, -2.2, -1);
	glTexCoord2d(1, 1);
	glVertex3d(-1, -2.2, -1);

	glEnd();
}

void QuadsIc2() {
	glBindTexture(GL_TEXTURE_2D, Image2);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glVertex3d(0, -2, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-1, -2, 0);
	glTexCoord2d(1, 1);


	glEnd();
}

void QuadsCapacitor1() {
	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, -2.2, 0);
	glTexCoord2d(1, 0);
	glVertex3d(0, -2.2, -1);
	glTexCoord2d(1, 1);
	glVertex3d(-1, -2.2, -1);

	glEnd();
}

void QuadsCapacitor2() {

	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(-1.1, -2.2, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0.1, -2.2, 0);
	glVertex3d(0.1, -1, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-1.1, -1, 0);
	glTexCoord2d(1, 1);


	glEnd();
}

void collected() {

	glTranslated(-1, 0, -3);
	QuadsCollected1();
	glPushMatrix();
	glTranslated(0, 0.5, 0);

	QuadsCollected1();
	glPopMatrix();
	glPushMatrix();
	QuadsCollected2();
	glTranslated(0, 0, -1);
	QuadsCollected2();
	glPopMatrix();

	//2
	glTranslated(-1, 0, 0);
	QuadsCollected1();
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	QuadsCollected1();
	glPopMatrix();
	glPushMatrix();
	QuadsCollected2();
	glTranslated(0, 0, -1);
	QuadsCollected2();
	glPopMatrix();

	//3
	glTranslated(1, 0, -1.5);
	QuadsCollected1();
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	QuadsCollected1();
	glPopMatrix();
	glPushMatrix();
	QuadsCollected2();
	glTranslated(0, 0, -1);
	QuadsCollected2();
	glPopMatrix();

	//4
	glTranslated(-1, 0, 0);
	QuadsCollected1();
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	QuadsCollected1();
	glPopMatrix();
	glPushMatrix();
	QuadsCollected2();
	glTranslated(0, 0, -1);
	QuadsCollected2();
	glPopMatrix();
}

void cpu() {

	glTranslated(-0.5, 0, 5);

	QuadsCpu1();
	glPushMatrix();
	glTranslated(0, 0.2, 0);
	QuadsCpu1();
	glPopMatrix();
	glPushMatrix();

	QuadsCpu2();
	glTranslated(0, 0, -1);
	QuadsCpu2();
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, 1);
	QuadsCpu2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -1);
	QuadsCpu2();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -2);
	QuadsCpu2();
	glPopMatrix();
}

void ram() {
	glTranslated(5.5, 0, -6);
	glRotated(90, 0, 1, 0);
	QuadsRam1();
	glPushMatrix();

	QuadsRam2();
	glTranslated(0, 0, -1);
	QuadsRam2();
	glPopMatrix();

	//2
	glTranslated(-1, 0, 0);
	QuadsRam1();
	glPushMatrix();

	glPushMatrix();
	QuadsRam2();
	glTranslated(0, 0, -1);
	QuadsRam2();
	glPopMatrix();

	//3 
	glTranslated(-1, 0, 0);
	QuadsRam1();
	glPushMatrix();

	glPushMatrix();
	QuadsRam2();
	glTranslated(0, 0, -1);
	QuadsRam2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -1);
	QuadsRam2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, 2);
	QuadsRam2();
	glPopMatrix();

	//the second sloat 
	glTranslated(2, 0, -1.5);

	QuadsRam1();
	glPushMatrix();

	QuadsRam2();
	glTranslated(0, 0, -1);
	QuadsRam2();
	glPopMatrix();

	//2
	glTranslated(-1, 0, 0);
	QuadsRam1();
	glPushMatrix();

	glPushMatrix();
	QuadsRam2();
	glTranslated(0, 0, -1);
	QuadsRam2();
	glPopMatrix();

	//3 
	glTranslated(-1, 0, 0);
	QuadsRam1();
	glPushMatrix();

	glPushMatrix();
	QuadsRam2();
	glTranslated(0, 0, -1);
	QuadsRam2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -1);
	QuadsRam2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, 2);
	QuadsRam2();
	glPopMatrix();

}

void chips() {

	glTranslated(-2.5, 0, 1);
	QuadsIc1();
	glPushMatrix();
	glTranslated(0, 0.2, 0);
	QuadsIc1();
	glPopMatrix();
	glPushMatrix();
	QuadsIc2();
	glTranslated(0, 0, -1);
	QuadsIc2();
	glPopMatrix();


	//2
	glTranslated(-1.4, 0, 1);
	QuadsIc1();
	glPushMatrix();
	glTranslated(0, 0.2, 0);
	QuadsIc1();
	glPopMatrix();
	glPushMatrix();
	QuadsIc2();
	glTranslated(0, 0, -1);
	QuadsIc2();
	glPopMatrix();

	// for wall

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(2, 0, 1);
	QuadsIc2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(2, 0, 1.5);
	QuadsIc2();
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, 0);
	QuadsIc2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -1);
	QuadsIc2();
	glPopMatrix();

}

void capacitor() {

	glTranslated(-2, 0, 0);
	glTranslated(0, 0, -3);
	QuadsCollected1();
	glPushMatrix();
	glTranslated(0, 0.5, 0);

	QuadsCollected1();
	glPopMatrix();
	glPushMatrix();
	QuadsCollected2();
	glTranslated(0, 0, -1);
	QuadsCollected2();
	glPopMatrix();


	glPushMatrix();

	glTranslated(-0.7, 1.2, 0);
	QuadsCapacitor1();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.7, 0, 0);
	QuadsCapacitor2();
	glTranslated(0, 0, -1);
	QuadsCapacitor2();
	glPopMatrix();

	//wall
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -1);
	QuadsCapacitor2();
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -1.5);
	QuadsCapacitor2();
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, -2);
	QuadsCollected2();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1, 0, 0);
	QuadsCollected2();
	glPopMatrix();


	//2
	glTranslated(-1, 0, 0);
	QuadsCollected1();
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	QuadsCollected1();
	glPopMatrix();
	glPushMatrix();
	QuadsCollected2();
	glTranslated(0, 0, -1);
	QuadsCollected2();
	glPopMatrix();
	
}

void HardDrive::drawModel()
{
	hardbody(0, 0, 0, 10, 5, 20);
	DownQuads();
	UpQuads();
	collected();
	cpu();
	ram();
	chips();
	capacitor();
	
}
