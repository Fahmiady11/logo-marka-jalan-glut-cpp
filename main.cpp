#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int postX1=0;
int postY1=0;
float a=1.0;
float b=0.0;
float c=0.0;
float rotasi =1.0;
float scaled=1.0;
void lingkaran(int xp, int yp, int r, int n){
    float a,x,y;
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex2d(x,y);
       }
    glEnd();
}
void display(){
    glClear (GL_COLOR_BUFFER_BIT);
            glPushMatrix();
             glRotated(rotasi,0,0,1);
             glScalef(scaled,scaled,0.0);
            //lingkaran
            glColor3f(a,b,c);
            lingkaran(0+postX1,0+postY1,9,50);
            glColor3f(1.0,1.0,1.0);
            lingkaran(0+postX1,0+postY1,8,50);
            glColor3f(a,b,c);
            lingkaran(0+postX1,0+postY1,7,50);

            //ketupat
            glBegin(GL_POLYGON);
             glColor3f(1.0,1.0,1.0);
             glVertex2d(-6+postX1,0+postY1);
             glVertex2d(0+postX1,6.5+postY1);
             glVertex2d(6+postX1,0+postY1);
             glVertex2d(0+postX1,-6.5+postY1);
            glEnd();

            //objek 1
            glBegin(GL_POLYGON);
             glColor3f(a,b,c);
             glVertex2d(-4+postX1,0+postY1);
             glVertex2d(-1.3+postX1,3+postY1);
             glVertex2d(1+postX1,3+postY1);
             glVertex2d(-1+postX1,1+postY1);
             glVertex2d(-1+postX1,-1+postY1);
             glVertex2d(1+postX1,-3+postY1);
             glVertex2d(-1.3+postX1,-3+postY1);
            glEnd();
             //objek 2
            glBegin(GL_POLYGON);
             glColor3f(a,b,c);
             glVertex2d(-1+postX1,1+postY1);
             glVertex2d(4+postX1,1+postY1);
             glVertex2d(4+postX1,-1+postY1);
             glVertex2d(-1+postX1,-1+postY1);
            glEnd();
            glPopMatrix();
            glFlush ();
}
void inputan(unsigned char key,int x,int y){
            //kanan
            if(key=='d' || key == 'D'){
                postX1 += 2;
               cout <<  postX1<< endl;
                display();
            }
            //kiri
            if(key == 'a' || key == 'A'){
                 postX1 -= 2;
                cout <<  postX1 << endl;
               display();
            }
            //atas
            if(key == 'w' || key == 'W'){
                 postY1+= 2;
                cout <<  postY1 << endl;
                display();
                }
            //bawah
            if(key == 's' || key == 'S'){
                 postY1 -= 2;
                cout <<  postY1 << endl;
                display();
            }
            //serong kiri atas
            if(key == 'q' || key == 'q'){
                 postX1-= 2;
                 postY1+= 2;
                cout <<  postY1 << endl;
                display();
                }
            //serong kanan atas
            if(key == 'e' || key == 'e'){
                postX1+= 2;
                postY1+= 2;
                cout <<  postY1 << endl;
                display();
            }
            //serong kiri bawah
            if(key == 'z' || key == 'z'){
                 postX1-= 2;
                 postY1-= 2;
                cout <<  postY1 << endl;
                display();
                }
            //serong kanan bawah
            if(key == 'c' || key == 'c'){
                 postX1+= 2;
                 postY1-= 2;
                cout <<  postY1 << endl;
                display();
            }

            //warna
            if(key == '1'){
                 a = 1.0;
                 b = 0.0;
                 c = 0.0;
                cout <<  "merah" << endl;
                display();
            }
            if(key == '2'){
                 a = 0.0;
                 b = 1.0;
                 c = 0.0;
                cout <<  "hijau" << endl;
                display();
            }
            if(key == '3'){
                 a = 0.0;
                 b = 0.0;
                 c = 1.0;
                cout <<  "biru" << endl;
                display();
            }
            if(key == '4'){
                 a = 1.0;
                 b = 1.0;
                 c = 0.0;
                cout <<  "kuning" << endl;
                display();
            }
            if(key == '5'){
                 a = 1.0;
                 b = 0.0;
                 c = 1.0;
                cout <<  "ungu" << endl;
                display();
            }
            if(key == '6'){
                 a = 0.0;
                 b = 1.0;
                 c = 1.0;
                cout <<  "biru muda" << endl;
                display();
            }

            //rotate kiri
             if (key == 'o' || key == 'O')
            {
                rotasi += 1;
                cout << rotasi << endl;
                display();
            }
            //rotate kanan
            if (key == 'p' || key == 'P')
            {
                rotasi -= 1;
                cout << rotasi << endl;
                display();
            }
            //reset ke titik 0 ketika mau rotate
            if (key == 'l' || key == 'L')
            {
                postX1=postX1*0;
                postY1=postY1*0;
                rotasi*=0;
                cout << rotasi << endl;
                display();
            }
            //zoom in
            if (key == 'm' || key == 'M')
            {
                scaled += 0.01;
                cout << scaled << endl;
                display();
            }
            //zoom out
            if (key == 'n' || key == 'N')
            {
                scaled -= 0.01;
                cout << scaled << endl;
                display();
            }


}

void myinit()
{
	glClearColor(1,1,1,0);  //untuk memberi warna pada background
	glColor3f(1.0, 0.0, 0.0); // color pada object
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20.0, 20.0, -20.0, 20.0);  // kordinat pada area menggambar
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(2);
}
int main(int argc, char *argv[])
{
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("TUGAS_UTS");
    glutDisplayFunc(display);
    glutKeyboardFunc(inputan);
    myinit();
    glutMainLoop();
    return 0;
}
