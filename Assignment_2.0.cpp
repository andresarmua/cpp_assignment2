#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include "Planet.h"

using namespace std;

int main() {
  
  string name;
  double mass;
  double x;
    
  ifstream myInput;
  myInput.open("input_1.txt");
  
  if(myInput.fail()){
  cout << "Sorry, file couldn't be opened" << endl;
  }


  myInput >> name >> mass >> x; 
  Planet Planet_1(name, mass, x);
  cout << name << "\t\t" << mass << "\t" << x << endl;

  
  myInput >> name >> mass  >> x; 
  Planet Planet_2(name, mass, x); 
  cout << name << "\t\t" << mass << "\t" << x << endl;
  
  
  myInput >> name >> mass >> x; 
  Planet Planet_3(name, mass, x);
  cout << name << "\t\t" << mass << "\t" << x << endl;


  myInput >> name >> mass >> x; 
  Planet Planet_4(name, mass, x);
  cout << name << "\t\t" << mass << "\t" << x << endl;
  
  myInput.close();

  Planet_4.set_mass(2);
  Planet_3.set_name("Melmac");
  
  cout << "Planet 3 name is: " << Planet_3.get_name() << endl;
  cout << "Planet 4 mass is: " << Planet_4.get_mass() << endl;

  return 0;
}
