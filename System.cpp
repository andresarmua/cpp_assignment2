#include "Planet.h"
#include "System.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const double G = 4.98217402368e-10; // Newton's Gravitational constant in unusual units ( km^3 d^-2 kg^-1))

System::System(){                   //Constructor creates a system with a massless planet located at the coordinate origin
  Planet U("null",0,0,0,0,0);
  vector<Planet> P;
  P.push_back(U);
  m_P = P;
}

System::System(vector<Planet> P){   //Constructor creates a system with the Planet vector input
  m_P = P;
}


void System::Evolve(double dt){     //Function evolves the system based on instantaneous gravitational interaction at each timestep
  
  int len = m_P.size();             //Define variable that contains the number of Planets(stars)
  vector<Planet> P_previous = m_P;  //Creates a copy of the Planets states to compute interactions leaving the positions and velocities unchanged and evolve them after that.
  
  for(int i=0;i!=len;i++){        
    double ax     = 0;              //initialises the accelerations=0
    double ay     = 0;
    double x_i    = P_previous[i].get_x();
    double y_i    = P_previous[i].get_y();
    double vx     = P_previous[i].get_vx();
    double vy     = P_previous[i].get_vy(); 


    //Now the total acceleration for Planet_i is computed by summing over all
    //contributions from all other Plantes j, (if statement prevents
    //consiering self-interaction (which would diverge))
    for(int j = 0 ; j!=len; j++){
      if(i != j){
        double ms_j  = P_previous[j].get_mass();
        double x_j   = P_previous[j].get_x();
        double y_j   = P_previous[j].get_y();
        ax = ax + (G*ms_j*(x_j-x_i)/pow(sqrt(pow((x_i-x_j),2) + pow((y_i-y_j),2)),3));   
        ay = ay + (G*ms_j*(y_j-y_i)/pow(sqrt(pow((x_i-x_j),2) + pow((y_i-y_j),2)),3));
      }
    }
  
    //Uncomment *'s lines if want to keep Sun fixed at 0,0 at all times.
    //* if(m_P[i].get_name() != "Sun"){
      m_P[i].Evolve(dt,ax,ay);
      //m_P[i].set_x(x_i  + vx*dt   + (1/2)*ax*dt*dt);
      //m_P[i].set_vx(vx  + ax*dt);
      //m_P[i].set_y(y_i  + vy*dt + (1/2)*ay*dt*dt);
      //m_P[i].set_vy(vy  + ay*dt);
    //* }
  }
}


    
vector<Planet> System::get_Planets(){   //Function to return Planet vector with evolved states
  return m_P;
}







