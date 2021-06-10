#include <iostream>
#include <vector>

class Rotor {
public:
  unsigned rotNumber;    // ROTOR ID. NOT USED IN COMPUTING
  unsigned ringstellung;           // RINGSTELLUNG

  unsigned display;      // DISPLAYED LETTER
  unsigned tick;



  std::vector<unsigned> scram; // FORWARD SCRAMBLING, 
      // LEFT TO RIGHT

  std::vector<unsigned> backscram; // BACKWARD SCRAMBLING, 
      // RIGHT TO LEFT


  Rotor(unsigned rotNumber, unsigned ringstellung) {
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
        tick = 16;
      case 2: this->scram= 
      // a j p c z w r l f b d k o
      // t y u q g e n h x m i v s
        tick = 16;
      break;
    }

    backscram = std::vector<unsigned>(scram.size());
    for(int i=0; i<scram.size(); ++i){
      backscram[scram[i]] = i;
    }
  }


  unsigned back (unsigned op) {
    unsigned len = scram.size();
    unsigned wp = ((display + len) - ringstellung)%len; // WIRING POSITION

    return ((backscram[(op+wp)%len] + len)-wp)%len;
  }



  unsigned forward (unsigned op) {
    unsigned len = scram.size();
    unsigned wp = ((display + len) - ringstellung)%len; // WIRING POSITION

    

    return ((scram[(op+wp)%len] + len)-wp)%len;
  }

  void setRing(unsigned op) {
    this->ringstellung = op;
  }
  void setDisplay(unsigned op) {
    this->display = op;
  }



  ~Rotor() {}
  
};


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


std::ostream & operator<< (std::ostream &out, 
      std::vector<unsigned> &op) {
  if (op.size() == 0) return out;
  out << op[0];
  for(int i=1; i<op.size(); ++i)
    out << ", " << op[i];
  return out;
}

int main(int argc, char const *argv[]) {
  
  Rotor a(1,1);
  Reflector c;

  std::cout << a.scram << std::endl;
  std::cout << a.backscram << std::endl;


  a.setRing(0);
  a.setDisplay(1);

  for (int i = 0; i < 3; ++i) {
    std::cout << i << " -> " << a.forward(i) << std::endl;
  }

  std::cout << "ref = " << c.wiring << std::endl;

  return 0;
}