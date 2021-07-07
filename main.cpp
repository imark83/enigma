#include <iostream>
#include "rotor.hpp"


class Enigma {
public:
  std::vector<Rotor> rotor;
  Reflector reflector;

  Enigma(unsigned rot1, unsigned rot2, unsigned rot3,
      unsigned ring1 = 0, unsigned ring2 = 0, unsigned ring3 = 0) {
    //Rotor r1(rot1,ring1);

    rotor = std::vector<Rotor>(3);

    rotor[0] = Rotor(rot1,ring1);
    rotor[1] = Rotor(rot2,ring2);
    rotor[2] = Rotor(rot3,ring3);

  }


  void tick(){
    if(rotor[1].tick_label == rotor[1].display) {
      rotor[0].tick();
      rotor[1].tick();
      rotor[2].tick();
    } else if (rotor[0].tick_label == rotor[0].display) {
      rotor[0].tick();
      rotor[1].tick();
    }
  }

  unsigned encode(unsigned op) {
    unsigned rop = rotor[0].back(rotor[1].back((rotor[2].back(op))));
    rop = reflector.back(rop);
    return rotor[2].forward(rotor[1].forward(rotor[0].forward(rop)));
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

  std::cout << "7 -> " << enigma.encode(7) << std::endl;

  return 0;
}