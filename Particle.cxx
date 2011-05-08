#ifndef PARTICLE_CXX
#define PARTICLE_CXX

#include "Particle.hxx"

/** Default construct. Initialize all coordinates randomly */
Particle::Particle() : 
mX(Ren::get(200)), 
mY(Ren::get(200)), 
mZ(Ren::get(200)), 
mVX(Ren::get(2) == 1 ? 1 : -1), 
mVY(Ren::get(2) == 1 ? 1 : -1), 
mVZ(Ren::get(2) == 1 ? 1 : -1),
mRadius(1),mGroup(Ren::get(5)) {}

/** Default destructor */
Particle::~Particle(){}

/** \return the X coordinate */
unsigned int Particle::getX() const { return mX; }

/** \return the Y coordinate */
unsigned int Particle::getY() const { return mY; }

/** \return the Z coordinate */
unsigned int Particle::getZ() const { return mZ; }

/** \return the X velocity */
int Particle::getVX() const { return mVX; }

/** \return the Y velocity */
int Particle::getVY() const { return mVY; }

/** \return the Z velocity */
int Particle::getVZ() const { return mVZ; }

/** \param vx set the x velocity */
void Particle::setVX(int vx){ mVX = vx; }

/** \param vy set the y velocity */
void Particle::setVY(int vy){ mVY = vy; }

/** \param vz set the z velocity */
void Particle::setVZ(int vz){ mVZ = vz; }

/** Collision checking Function */
bool Particle::collides(const Particle& p){
  bool col = true;
  if (this != &p){
    // TODO this might need to be changed with particle radius
    if (this->mX != p.getX()) col = false;
    if (this->mY != p.getY()) col = false;
    if (this->mZ != p.getZ()) col = false;
  } else {
    std::cout << "Warning, collision checking against the same particle!" << std::endl;
    return false;
  }
  this->mGroup = 6;
  return col;
}

/** Simple printing */
void Particle::print(){
  std::cout << "[" << std::setw(3) << std::right << mX << "][" << std::setw(3) 
            << std::right << mY << "][" << std::setw(3) << std::right << mZ 
            << "]  vx[" << std::setw(3) << std::right << mVX << "] vy[" 
            << std::setw(3) << std::right << mVY << "] vz [" << std::setw(3) 
            << std::right << mVZ << "] group [" << std::setw(3) 
            << std::right << int(mGroup) << "]" << std::endl;
}

/** Basic particle function to do a timestep for a particle */
void Particle::step(){
  mX += mVX;
  mY += mVY;
  mZ += mVZ; 

  switch(mGroup){
    case 0: glColor3f(1.0f, 0.0f, 0.0f); break;
    case 1: glColor3f(0.0f, 1.0f, 0.0f); break;
    case 2: glColor3f(0.0f, 0.0f, 1.0f); break;
    case 3: glColor3f(1.0f, 1.0f, 0.0f); break;
    case 4: glColor3f(0.0f, 1.0f, 1.0f); break;
    case 5: glColor3f(1.0f, 0.0f, 1.0f); break;
    default: glColor3f(1.0f, 1.0f, 1.0f); break;
  }
  glBegin(GL_POINTS);
    // TODO change 200
    glVertex3f(float(mX)/200 - 0.5, float(mY)/200 - 0.5, float(mZ)/200 - 0.5);
  glEnd();
}

void Particle::setGroup(int x){
  mGroup = x;
}

#endif 

