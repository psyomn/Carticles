#ifndef BOX_CXX
#define BOX_CXX

#include "Box.hxx"

/** Default constructor. Initialiaze room space */
Box::Box() : mStandardMax(200), mStandardMin(0), 
mMaxX(mStandardMax), mMaxY(mStandardMax), mMaxZ(mStandardMax),
mMinX(mStandardMin), mMinY(mStandardMin), mMinZ(mStandardMin),
mNumOfParticles(0){
}

/** Constructor to create box, with \param n particles */
Box::Box(unsigned int n) : mStandardMax(200), 
mStandardMin(0), mMaxX(mStandardMax), mMaxY(mStandardMax), 
mMaxZ(mStandardMax), mMinX(mStandardMin), mMinY(mStandardMin),
mMinZ(mStandardMin), mNumOfParticles(n){
  Particle* k;
  unsigned int i;

  for (i=0; i<n; ++i){
    k = new Particle;
    mParticleVector.push_back(*k);
  }
}

/** Default destructor. Clear the vector */
Box::~Box(){
  mParticleVector.clear();
}

/** Add a particle to the vector */
void Box::addParticle(Particle p){
  mParticleVector.push_back(p);
}

/** Remove contents from the vector */
void Box::clear(){
  mParticleVector.clear();
}

/** Print all the particles */
void Box::print(){
  std::vector<Particle>::iterator it;

  for(it = mParticleVector.begin(); it != mParticleVector.end(); ++it){
    (*it).print();
  }
}

/** A simulation step on all the particles. Here there should be collision
checking against walls, and each other particle. Time complexity is pretty
bad here, but the scope of this project is not performance. */
void Box::step(){
  std::vector<Particle>::iterator it;
  std::vector<Particle>::iterator it2;

  /* Do a timestep */
  for (it=mParticleVector.begin(); it!=mParticleVector.end(); ++it){
    (*it).step();
  }

  /* Wall collision check */
  for (it=mParticleVector.begin(); it!=mParticleVector.end(); ++it){
    // Max Wall Collisions
    if ( (*it).getX() > mMaxX || (*it).getX() == 0 ) (*it).setVX(-(*it).getVX());
    if ( (*it).getY() > mMaxY || (*it).getY() == 0 ) (*it).setVY(-(*it).getVY()); 
    if ( (*it).getZ() > mMaxZ || (*it).getZ() == 0 ) (*it).setVZ(-(*it).getVZ()); 
  }
  
  /* Particle collision check */
  for (it=mParticleVector.begin(); it!=mParticleVector.end(); ++it){
    it2 = it;

    /* Check 1 particle against all the rest */
    for (++it2; it2 != mParticleVector.end(); ++it2){
      if ( (*it).getX() == (*it2).getX() &&
           (*it).getY() == (*it2).getY() &&
           (*it).getZ() == (*it2).getZ() ){
        std::cout << "Particle Collision!" << std::endl;
        (*it).setVX(-(*it).getVX());
        (*it).setVY(-(*it).getVY());
        (*it).setVZ(-(*it).getVZ());

        (*it2).setVX(-(*it).getVX());
        (*it2).setVY(-(*it).getVY());
        (*it2).setVZ(-(*it).getVZ());
      }
    }
  }
}

/** \return the number of particles */
unsigned int Box::getNumOfParticles(){
  return mNumOfParticles;
}

#endif

