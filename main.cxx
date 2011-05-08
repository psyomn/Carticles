/** \mainpage this is another particle simulator written the "proper" way. 
Well, to some extent. It has enabled wall collisions and particle collisions. I have
not taken into consideration efficiency so the actual way for each collision cycle
should be On2. In this project I was more interested in using OpenGL in an object
oriented manner, and to start implementing simple design patterns. Also was interested
in achieving low coupling. 

\author psyomn

*/

#include <iostream>
#include <pthread.h>

#include <GL/glut.h>
#include <GL/gl.h>

#include "Particle.hxx"
#include "Ren.hxx" 
#include "Box.hxx"

void render();
void setup();

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(20, 20);
  glutCreateWindow("Carticles");
  setup();
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
}

void setup(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glPointSize(2);
  glColor3f(0.0f, 1.0f, 0.0f);
  glRotatef(27.0, 1.0, 0.0, 0.0);
  glRotatef(27.0, 0.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
}

void render(){
  Box b(300);

  b.print();

  while(1){ 
    glClear(GL_COLOR_BUFFER_BIT);
    b.step(); 

    glRotatef(0.2f, 0.0f, 0.2f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireCube(1.0);
    glEnd();

    glutSwapBuffers();
    usleep(7000);
  } 

  std::cout << std::endl << "-----" << std::endl;

  b.print();

}
