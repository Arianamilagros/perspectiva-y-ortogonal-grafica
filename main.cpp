#include <windows.h>
#include <GL/glut.h>

//char title[] = "Ortogonal"; //cuando es modo 0
char title[] = "Pespectiva"; //cuando es modo 1
int modo=0;
int refreshMills = 15;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   glTranslatef(0.0f, 0.0f, -7.0f);

   glRotatef(15.0f, 0.5f, 1.0f, 0.0f);

   glBegin(GL_QUADS);

      glColor3f(0.0f, 1.0f, 0.0f);     // verde
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      glColor3f(1.0f, 0.5f, 0.0f);     // color naranja
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      glColor3f(1.0f, 0.0f, 0.0f);     // rojo
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      glColor3f(1.0f, 1.0f, 0.0f);     // color amarl
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      glColor3f(0.0f, 0.0f, 1.0f);     // color azul
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      glColor3f(1.0f, 0.0f, 1.0f);     // color Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();

   glLoadIdentity();


   glutSwapBuffers();
}

void modelc(GLsizei width, GLsizei height) {

   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   if(modo==0)
   {
       if (width >= height) {
          glOrtho(-3.0 * aspect, 3.0 * aspect, -3.0, 3.0, 0.1, 100);
       } else {
         glOrtho(-3.0, 3.0, -3.0 / aspect, 3.0 / aspect, 0.1, 100);
       }
   }
   else
   {
       gluPerspective(45.0f, aspect, 0.1f, 100.0f);
   }
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow(title);
   glutDisplayFunc(display);
   glutReshapeFunc(modelc);
   initGL();
   glutMainLoop();
   return 0;
}
