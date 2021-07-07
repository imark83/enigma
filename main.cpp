#include <iostream>
#include <string>
#include "rotor.hpp"

char toChar(unsigned op) {
  if (op == 26) return ' ';
  return 'A' + op;
}

class Enigma {
public:
  std::vector<Rotor> rotor;
  Reflector reflector;
  std::vector<unsigned> plugbloard;

  Enigma(unsigned rot1, unsigned rot2, unsigned rot3, unsigned notB = 1,
      unsigned ring1 = 0, unsigned ring2 = 0, unsigned ring3 = 0) : reflector(notB) {
    //Rotor r1(rot1,ring1);

    rotor = std::vector<Rotor>(3);

    plugbloard = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,
                  13,14,15,16,17,18,19,20,21,22,23,24,25};    

    rotor[0] = Rotor(rot1,ring1);
    rotor[1] = Rotor(rot2,ring2);
    rotor[2] = Rotor(rot3,ring3);

  }

  void setDisplay(unsigned d1, unsigned d2, unsigned d3) {
    rotor[0].setDisplay(d1);
    rotor[1].setDisplay(d2);
    rotor[2].setDisplay(d3);
  }

  void setPlug(unsigned op1, unsigned op2) {
    plugbloard[op1] = op2;
    plugbloard[op2] = op1;
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
    if(op == ' ') return 26;
    tick();
    unsigned rop = plugbloard[op];
    rop = rotor[0].back(rotor[1].back((rotor[2].back(op))));
    rop = reflector.back(rop);
    rop = rotor[2].forward(rotor[1].forward(rotor[0].forward(rop)));
    return plugbloard[rop]; 
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
  

// Tag  Walzenlage  Ringstellung  ---- Steckerverbindungen ----
//   7  II  IV  V     02 21 12    AV BS CG DL FU HZ IN KM OW RX


  Enigma enigma(2,4,5,1,1,20,11);
  enigma.setPlug(0,21);  enigma.setPlug(1,18); 
  enigma.setPlug(2,6);   enigma.setPlug(3,11);
  enigma.setPlug(5,20);  enigma.setPlug(7,25);
  enigma.setPlug(8,13);  enigma.setPlug(10,12);
  enigma.setPlug(14,22); enigma.setPlug(17,23);

  enigma.setDisplay(22,23,2);

  std::string msg("KCH");

  for (char c : msg) {
    std::cout << toChar(enigma.encode(c));
  }
  std::cout << std::endl;


  return 0;
}