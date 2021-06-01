#include <iostream>
#include <vector>

class Rotor {
public:
  int rotNumber;
  int ringstellung;

  int position;
  std::vector<unsigned int> scrambling;


  Rotor(int rotNumber, int ringstellung) {
    this->rotNumber = rotNumber;
    this->ringstellung = ringstellung;
    this->position = 0;
    //this->scrambling = std::vector<unsigned int>(3,4,5);
    switch (rotNumber) {
      case 1: this->scrambling = 
        {20,22,24,03,22,24,25,08,13,16,17,19,16,23,
         24,04,Q,R,S,T,U,V,W,X,Y,Z};
  }




  ~Rotor() {}
  
};



int main(int argc, char const *argv[]) {
  
  Rotor a(1,2);

  return 0;
}