#ifndef REN_CXX
#define REN_CXX

#include "Ren.hxx"

// TODO this should be implemented as a singleton class

/** Default Constructor. Generate the random seed using time */
Ren::Ren(){
  srand( time ( 0 ) );
}

/** Default destructor */
Ren::~Ren(){
}

/** \return a random number */
unsigned int Ren::get(){
  return rand();
}

/** \return a random number from a range of 0 to n */
unsigned int Ren::get(unsigned int range){
  return rand()%range;
}

#endif

