#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "Planet.h"
#include "System.h"

using namespace std;

//const double G = 6.67408e-17;  // Newton's Gravitational constant in unusual units (N km^2/kg^2)

int main(int argc, char** argv){


  string name;
  double mass;
  double x;
  double y;
  double vx;
  double vy;
  double DT = atof(argv[2]);
  double dt = atof(argv[1]);  


  ifstream myInput;
  myInput.open("input_2.txt");
  
  if(myInput.fail()){
  cout << "Sorry, file couldn't be opened" << endl;
  }
  


  vector<Planet> P_in;
  int l = 0;

  while(!myInput.eof()){
    myInput >> name >> mass >> x >> y >> vx >> vy; 
    Planet v(name, mass, x/1000, y/1000, 24*3.6*vx, 24*3.6*vy);
    if(!myInput.eof()){
      P_in.push_back(v);
    }
  }

  myInput.close();
  System Solar(P_in);
  int i_f = DT/dt;
  vector<ofstream> myOutput(10);
    
  for(int j = 0; j!= P_in.size(); j++){ 
	myOutput[j].open(P_in[j].get_name()+"_evolution.txt");
	if (myOutput[j].fail()){
	    cout << "Sorry, couldn't write this file" << endl;
	    exit(1);
	}
    myOutput[j] << "#" << "\t" << "t(d)" << "\t" << "x" << "\t\t\t" << "y" << endl;  
  }


  for(int i = 0; i != i_f ; i++){
    Solar.Evolve(dt);
    vector<Planet> P_out = Solar.get_Planets();
	// write to files
    for(int j = 0; j != P_in.size(); j++){ 
      myOutput[j] << i+1 << "\t" << i*dt << "\t" << P_out[j].get_x() << "\t" << P_out[j].get_y() << endl;     
    }
  }
  for(int j = 0; j != P_in.size(); j++){
    myOutput[j].close();
  }

  if(i_f*dt != DT){
  cout << "Warning: Total time DT is not a multiple of step time dt" << endl;
  }
  return 0;
}
