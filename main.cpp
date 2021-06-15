#include <iostream>
#include "rotor.hpp"


class Enigma {
public:
  std::vector<Rotor> rotor;
  Enigma(unsigned rot1, unsigned rot2, unsigned rot3,
      ring1 = 0, ring2 = 0, ring3 = 0) {
    rotor = {Rotor(rot1)};
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