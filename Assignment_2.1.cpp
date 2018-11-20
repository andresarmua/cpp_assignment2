#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "Planet.h"


using namespace std;


int main(){


  string name;
  double mass;
  double x;
    
  ifstream myInput;
  myInput.open("input_1.txt");
  
  if(myInput.fail()){
  cout << "Sorry, file couldn't be opened" << endl;
  }
  


  vector<Planet> P;
  int l = 0;

  while(!myInput.eof()){
    myInput >> name >> mass >> x; 
    Planet v(name, mass, x);
    if(!myInput.eof()){
      P.push_back(v);
    }
  }

  myInput.close();
  

  cout << "\n";

  int len = P.size();

  for(int i=0;i<len;i++){
  cout << P[i].get_name() << endl; 
  }
  return 0;
}
