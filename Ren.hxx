#ifndef REN_HXX
#define REN_HXX

#include <cstdlib>
#include <ctime>

/** A wrapper for getting random numbers */ 
class Ren {
public:
  Ren();
  ~Ren();
  static unsigned int get();
  static unsigned int get(unsigned int);
private:

};

#endif

