#ifndef PARTICLE_HXX
#define PARTICLE_HXX

#include <iostream>
#include <iomanip>
#include <GL/glut.h>
#include <GL/gl.h>
#include "Ren.hxx" 

/** Class managing functions of single particles, coordinates, velocities */
class Particle {
public: 
  Particle();
  ~Particle();

  // Mutators / Accessors
  unsigned int getX() const;
  unsigned int getY() const;
  unsigned int getZ() const;
  int getVX() const;
  int getVY() const;
  int getVZ() const;
  unsigned int getRadius() const;

  void setVX(int);
  void setVY(int);
  void setVZ(int);
  void setGroup(int);

  // Functions
  bool collides(const Particle&);
  void print();
  void step();

private:
  unsigned int mX; /** X coordinate */
  unsigned int mY; /** Y coordinate */
  unsigned int mZ; /** Z coordinate */

  int mVX; /** X velocity */
  int mVY; /** Y velocity */
  int mVZ; /** Z velocity */ 

  unsigned char mRadius; /** The particle radius */
  unsigned char mGroup; /** The particle group (determines color) */
};

#endif

