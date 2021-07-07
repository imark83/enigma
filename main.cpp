#include <iostream>
#include <string>
#include "rotor.hpp"

char toChar(unsigned op) {
  return 'A' + op;
}

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

  void setDisplay(unsigned d1, unsigned d2, unsigned d3) {
    rotor[0].setDisplay(d1);
    rotor[1].setDisplay(d2);
    rotor[2].setDisplay(d3);
  }


  void tick(){
    if(rotor[1].tick_label == rotor[1].display) {
      rotor[0].tick();
      rotor[1].tick();
      rotor[2].tick();
    } else if (rotor[2].tick_label == rotor[2].display) {
      rotor[2].tick();
      rotor[1].tick();
    } else rotor[2].tick();
  }

  unsigned encode(unsigned op) {
    tick();
    unsigned rop = rotor[0].back(rotor[1].back((rotor[2].back(op))));
    rop = reflector.back(rop);
    return rotor[2].forward(rotor[1].forward(rotor[0].forward(rop)));
  }


  unsigned encode(char op) {
    unsigned aux = op;
    aux -= 'A';
    return encode(aux);
  }

  ~Enigma() {}
  
};

std::ostream & operator<<(std::ostream &out, const Enigma &enigma) {
  out << "(" << toChar(enigma.rotor[0].display) <<",";
  out << toChar(enigma.rotor[1].display) <<",";
  out << toChar(enigma.rotor[2].display) <<")";

  return out;
}


std::ostream & operator<< (std::ostream &out, 
      std::vector<unsigned> &op) {
  if (op.size() == 0) return out;
  out << op[0];
  for(int i=1; i<op.size(); ++i)
    out << ", " << op[i];
  return out;
}

int main(int argc, char const *argv[]) {
  
  Enigma enigma(1,2,3,9,13,20);
  enigma.setDisplay(23,24,25);

  std::string msg("QKTPEBZIUK");

  for (char c : msg) {
    std::cout << toChar(enigma.encode(c));
  }
  std::cout << std::endl;


  return 0;
}