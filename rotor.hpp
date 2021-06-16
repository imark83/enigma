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


  Rotor(unsigned rotNumber, unsigned ringstellung);


  unsigned back (unsigned op);
  unsigned forward (unsigned op);

  void setRing(unsigned op);
  void setDisplay(unsigned op);



  ~Rotor() {}
  
};

Rotor & operator=(Rotor &op1, Rotor &op2) {
  op1.rotNumber=op2.rotNumber;    // ROTOR ID. NOT USED IN COMPUTING
  op1.ringstellung=op2.ringstellung;           // RINGSTELLUNG

  op1.display=op2.display;      // DISPLAYED LETTER
  op1.tick_label=op2.tick_label;



  op1.scram = op2.scram; // FORWARD SCRAMBLING, 
      // LEFT TO RIGHT

  op1.backscram = op2.backscram; // BACKWARD SCRAMBLING, 
      // RIGHT TO LEFT


  return op1;
}

class Reflector {
public:


  std::vector<unsigned> wiring; // FORWARD SCRAMBLING, 

  Reflector() {
    wiring = {
      24,17,20, 7,16,18,11, 3,15,23,13, 6,14,
      10,12, 8, 4, 1, 5,25, 2,22,21, 9, 0,19};
  }
  ~Reflector() {}
  
};


#endif