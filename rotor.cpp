#include "rotor.hpp"


Rotor::Rotor(const Rotor &op) {
  this->rotNumber = op.rotNumber;
  this->ringstellung = op.ringstellung;

  this->display = op.display;
  this->tick_label = op.tick_label;

  this->scram = op.scram;
  this->backscram = op.backscram;

}


Rotor::Rotor(unsigned rotNumber, unsigned ringstellung) {
  this->rotNumber = rotNumber;
  this->ringstellung = ringstellung;
  this->display = 0;  


  switch (rotNumber) {
    case 0: this->scram=
        {1,2,0,4,3};
      break;
    case 1: this->scram= 
        {20,22,24, 6, 0, 3, 5,15,21,25, 1, 4, 2,
         10,12,19, 7,23,18,11,17, 8,13,16,14, 9};
        tick_label = 16;
      break;
    case 2: this->scram= 
        {0,9,15,2,25,22,17,11,5,1,3,10,14,
         19,24,20,16,6,4,13,7,23,12,8,21,18};
        tick_label = 4;
      break;
    case 3: this->scram= 
        {19,0,6,1,15,2,18,3,16,4,20,5,21,
        13,25,7,24,8,23,9,22,11,17,10,14,12};
        tick_label = 21;
      break;
    case 4: this->scram= 
        { 7,25,22,21, 0,17,19,13,11, 6,20,15,23,
         16, 2, 4, 9,12, 1,18,10, 3,24,14, 8, 5};
        tick_label = 9;
      break;
    case 5: this->scram= 
        {16, 2,24,11,23,22, 4,13, 5,19,25,14,18,
         12,21, 9,20, 3,10, 6, 8, 0,17,15, 7, 1};
        tick_label = 25;
      break;
  }

  backscram = std::vector<unsigned>(scram.size());
  for(int i=0; i<scram.size(); ++i){
    backscram[scram[i]] = i;
  }
}


void Rotor::tick() {
  this->display++;
  if(this->display>=26) this->display=0;

  return;
}



Rotor & Rotor::operator=(const Rotor &op2) {
  this->rotNumber=op2.rotNumber;
  this->ringstellung=op2.ringstellung;

  this->display=op2.display;
  this->tick_label=op2.tick_label;

  this->scram = op2.scram;
  this->backscram = op2.backscram;


  return *this;
}

unsigned Rotor::back (unsigned op) {
  unsigned len = scram.size();
  unsigned wp = ((display + len) - ringstellung)%len; // WIRING POSITION

  return ((backscram[(op+wp)%len] + len)-wp)%len;
}



unsigned Rotor::forward (unsigned op) {
  unsigned len = scram.size();
  unsigned wp = ((display + len) - ringstellung)%len; // WIRING POSITION

  

  return ((scram[(op+wp)%len] + len)-wp)%len;
}

void Rotor::setRing(unsigned op) {
  this->ringstellung = op;
}
void Rotor::setDisplay(unsigned op) {
  this->display = op;
}

