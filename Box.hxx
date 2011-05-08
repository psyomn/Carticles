#ifndef BOX_HXX
#define BOX_HXX

#include <iostream>
#include <vector> 

#include "Particle.hxx"

/** Container for all the particles. This class is also responsible for collision detection
amongst particles and walls. */
class Box {
public: 
  Box();
  Box(unsigned int);
  ~Box();
  void addParticle(Particle);
  void clear();
  void step();
  void print();
  unsigned int getNumOfParticles();

private:
  unsigned int mStandardMax; /** Use this if you prefer a uniform room */
  unsigned int mStandardMin; /** Use this if you prefer a uniform room */  
  unsigned int mMaxX; /** Max X wall */
  unsigned int mMaxY; /** Max Y wall */ 
  unsigned int mMaxZ; /** Max Z wall */
  unsigned int mMinX; /** Min X wall */
  unsigned int mMinY; /** Min Y wall */
  unsigned int mMinZ; /** Min Z wall */
  unsigned int mNumOfParticles; /** Amount of particles inside the simulation */
  std::vector<Particle> mParticleVector; /** List of particles */
};

#endif 

