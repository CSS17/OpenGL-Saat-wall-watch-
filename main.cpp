#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define radius 17
#define yaricap 15
#define PI 3.14
#include <stdio.h>
#include <time.h>
int omen=0;
int yoru=0;
int viper=0;

void display(){
    int sayac=0;
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(10.0);
    glColor3f(0,0,1);
     glPointSize(3.0);
     double x,y,ret,value;
     value=PI/180;
     ret=sin(x*value);
    glBegin(GL_POLYGON);

      glColor3f(1,1,1);
    for(double i = 0; i < 360; i++){
    glColor3f(1,1,1);
      glPointSize(3.0);
      x = radius * sin(((double)i));
      y = radius * cos(((double)i));
      glVertex2f(x,y);
    }
    glEnd();
    char rakamlar[]="123456789101112";
    int gezici=0;
    double saatler[12];
    double saatler1[720];
    double dakikalar[60];
    int dolasan=0;
    int dolasan1=0;
    for(float i=90;i>-270;i-=0.5){
        saatler1[dolasan1]=i;
        dolasan1++;
    }



    for(int i = 60; i >= -300; i-=30){
            double xx = yaricap * cos((value*i));
            double yy = yaricap * sin((value*i));
            if(i%30==0){
            glColor3f(0,0,1);
            saatler[dolasan]=i;
            dolasan++;


            if(gezici<9){
                glRasterPos2f(xx,yy);
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,rakamlar[gezici]);
            }

            else{
                glRasterPos2f(xx,yy);
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,rakamlar[gezici]);
                glRasterPos2f(xx+1,yy);
               glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,rakamlar[gezici+1]);
                gezici++;
            }

            gezici++;
            }

    }
    glPointSize(10.0);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glVertex2f(0.5,0.5);
    glEnd();
    //YELKOVAN
    glLineWidth(5.8);
    glBegin(GL_LINES);
    glVertex2f(0.5,0.5);
    glVertex2f(cos(saatler1[omen]*(PI/180))*15+0.5,sin(saatler1[omen]*(PI/180))*15+0.5);
    glEnd();
    //AKREP
    int avci=0;
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.5,0.5);
    glVertex2f(cos(saatler1[yoru]*(PI/180))*10+0.5,sin(saatler1[yoru]*(PI/180))*10+0.5);
    glEnd();
    //SANİYE
    glLineWidth(3.8);
    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex2f(0.5,0.5);
    glVertex2f(cos(saatler1[viper]*(PI/180))*12+0.5,sin(saatler1[viper]*(PI/180))*12+0.5);
    glEnd();


    for(int i=60;i>=-300;i-=6){
        double x1 = yaricap * cos((value*i))-0.5;
        double y1 = yaricap * sin((value*i))-0.5;
        if(i%6==0){
             glColor3f(0,0,1);
             glPointSize(3.0);
             if(i%30!=0){
            glColor3f(1,0,0);
             glBegin(GL_POINTS);
             glVertex2f(x1+1,y1+1);
             }
             else


             glEnd();
        }


    }




    glutSwapBuffers();
    time_t  currentTime;
    time(&currentTime);
    struct tm * myTime=localtime(&currentTime);
    omen=myTime->tm_min*12;
    yoru=myTime->tm_hour %12 * 60 + myTime->tm_min;
    viper=myTime->tm_sec*12;
    glFlush();

}

void Idle(){
glutPostRedisplay();

}


void init(){
    glClearColor(0.5,0,1,0);
}
void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);
    glMatrixMode(GL_MODELVIEW);


}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(600,100);
    glutInitWindowSize(700,700);
    glutCreateWindow("My Window");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutIdleFunc(Idle);
    glutMainLoop();


}





