#ifndef __ROTOR_HPP__
#define __ROTOR_HPP__

#include <vector>

class Rotor {
public:
  unsigned rotNumber;    // ROTOR ID. NOT USED IN COMPUTING
  unsigned ringstellung;           // RINGSTELLUNG

  unsigned display;      // DISPLAYED LETTER
  unsigned tick_label;



  std::vector<unsigned> scram; // FORWARD SCRAMBLING, 
      // LEFT TO RIGHT

  std::vector<unsigned> backscram; // BACKWARD SCRAMBLING, 
      // RIGHT TO LEFT


  Rotor() {}
  Rotor(const Rotor &);
  Rotor(unsigned rotNumber, unsigned ringstellung);


  unsigned back (unsigned op);
  unsigned forward (unsigned op);

  void setRing(unsigned op);
  void setDisplay(unsigned op);
  void tick();

  Rotor & operator=(const Rotor &op2) ;


  ~Rotor() {}

  
};



class Reflector {
public:


  std::vector<unsigned> wiring; // FORWARD SCRAMBLING, 

  Reflector(unsigned notB = 1) {
    if(notB)
      wiring = {
      24,17,20, 7,16,18,11, 3,15,23,13, 6,14,
      10,12, 8, 4, 1, 5,25, 2,22,21, 9, 0,19};
    else
      wiring = {
        5,21,15, 9, 8, 0,14,24, 4, 3,17,25,23,
       22, 6, 2,19,10,20,16,18, 1,13,12, 7,11};
  }

  unsigned back(unsigned op) {
    return wiring[op];
  }
  ~Reflector() {}
  
};


#endif