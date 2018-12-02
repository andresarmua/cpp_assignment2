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



int main(int argc, char** argv){        //Pass command line arguments 

  //Declare planet parameters 
  
  string name;   
  double mass;
  double x;
  double y;
  double vx;
  double vy;


  //Define the timestep dt and the total runtime DT
  
  double DT = atof(argv[2]);   //
  double dt = atof(argv[1]);  


  // create Input object and import input_2.txt file 
  
  ifstream myInput;
  myInput.open("input_2.txt");
  if(myInput.fail()){
    cout << "Sorry, file couldn't be opened" << endl;
  }
  

  //Declare a Planet vector that will contain all Planet objects in their initial state
  vector<Planet> P_in;
  
  //Read the input file and create one object for each Planet
  while(!myInput.eof()){
    myInput >> name >> mass >> x >> y >> vx >> vy;
    //Mass is kg, distances are transformed from m to km and velocities from m/s to km/d
    Planet v(name, mass, x/1000, y/1000, 24*3.6*vx, 24*3.6*vy);      if(!myInput.eof()){
      P_in.push_back(v);    //Push objects into the Planet vector
    }
  }
  myInput.close();
  


  System Solar(P_in);                     //Create a new object containing a vector with the state (x,y,vx,vy) of all planets at a time t=0
  int i_f = DT/dt + 1;                    //Defines a variable that is the total number of steps in the discrete time evolution 
  vector<ofstream> myOutput(P_in.size()); //Creates vector containing outputs objects to write in output files
  


  //Different output files for each planet evolution are created, columns are "number of steps" - "time (days)" - "x position" - "y position" 
  
  for(int j = 0; j!= P_in.size(); j++){ 
	myOutput[j].open(P_in[j].get_name()+"_evolution.txt");
	if (myOutput[j].fail()){
	    cout << "Sorry, couldn't write this file" << endl;
	    exit(1);
	}
    myOutput[j] << "#" << "\t" << "t(d)" << "\t" << "x" << "\t\t\t" << "y" << endl;  
  }
  

  //Define boolean vector to make sure that the period is printed only once"
  bool P_written[P_in.size()];
  for (int i = 0; i != P_in.size(); i++){
    P_written[i] = false;
  }



  //Now the system is evolved, output for each step written the corresponding file and period of each planet is determined

  for(int i = 0; i != i_f ; i++){
    Solar.Evolve(dt);                                   //Evolve the system one step
    vector<Planet> P_out = Solar.get_Planets();         //get Planet states after evolving one step
    double x_star;                                      //declare variables for position of Sun (it is free to move)
    double y_star;                                      
    for(int j = 0; j != P_in.size(); j++){if(P_out[j].get_name() == "Sun"){x_star = P_out[j].get_x(); y_star = P_out[j].get_y();}}  //Position of Sun
      for(int j = 0; j != P_in.size(); j++){              //Prints positions in output files and observes if the planet completed a period
        myOutput[j] << i+1 << "\t" << i*dt << "\t" << P_out[j].get_x() << "\t" << P_out[j].get_y() << endl;  //writes file
        double alpha;                                                                                        //angle of planet with x axis respect to the sun
        if(P_out[j].get_x() - x_star != 0){alpha = atan((P_out[j].get_y()-y_star)/(P_out[j].get_x()-x_star));} //computes angle
      

        /*A full orbit is completed when the planet rotates an angle of 2*pi around the Sun. So if  |angle| < 4e-5 (in rad), 
        and x>0, and time > 30days then it is assumed that planet (not moon nor sun) completed an orbit. This is an approximation, orbit precession is        not considered */

        if(abs(alpha) < 4e-5 & i*dt > 30 & P_out[j].get_name() !="Sun" & P_out[j].get_x()>0 & P_out[j].get_name() != "Moon" & P_written[j] == false){
          P_written[j] = true;        //This avoids printing the period multiple times (eg. when a planet complits orbit for the second time)
          float T = i*dt + 0.5;       //variable for the float period (the +0.5 is to round the float correctly
          int Period = (int) T;       //want integer number, since the calculation is approximate (as described above)
          cout << P_out[j].get_name() << " period is = " << Period << " days" << endl;
        }
            
    }
    
  }



  //Close output files
  
  for(int j = 0; j != P_in.size(); j++){
    myOutput[j].close();
  }



  //Prints warning if DT is not a multiple of dt
  
  if((i_f-1)*dt != DT){
  cout << "Warning: Total time DT is not a multiple of step time dt" << endl;
  }


  return 0;
}
