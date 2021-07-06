#include <iostream>
#include "rotor.hpp"


class Enigma {
public:
  std::vector<Rotor> rotor;
  Enigma(unsigned rot1, unsigned rot2, unsigned rot3,
      unsigned ring1 = 0, unsigned ring2 = 0, unsigned ring3 = 0) {
    //Rotor r1(rot1,ring1);

    rotor = {Rotor(rot1,ring1),
             Rotor(rot2,ring2),
             Rotor(rot3,ring3)
    };
  }
  ~Enigma() {}
  
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
  
  Enigma enigma(1,2,3);

  return 0;
}