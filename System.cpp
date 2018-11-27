#include "Planet.h"
#include "System.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const double G = 4.98217402368e-10;  // Newton's Gravitational constant in unusual units ( km^3 d^-2 kg^-1))

System::System(){
 // Planet Unknown();
 // vector<Planet> P;
 // P.push_back(Unknown);
 // m_P = P;
}

System::System(vector<Planet> P){
  m_P = P;
}


void System::Evolve(double dt){
  
  int len = m_P.size();
  vector<Planet> P_previous = m_P;
  
  for(int i=0;i<len;i++){  
    double ax     = 0;
    double ay     = 0;
    double x_i    = P_previous[i].get_x();
    double y_i    = P_previous[i].get_y();
    double vx     = P_previous[i].get_vx();
    double vy     = P_previous[i].get_vy(); 

    for(int j = 0 ; j<len; j++){
      if(i != j){
        double ms_j  = P_previous[j].get_mass();
        double x_j   = P_previous[j].get_x();
        double y_j   = P_previous[j].get_y();
        ax = ax + (G*ms_j*(x_j-x_i)/pow(sqrt(pow((x_i-x_j),2) + pow((y_i-y_j),2)),3));
        ay = ay + (G*ms_j*(y_j-y_i)/pow(sqrt(pow((x_i-x_j),2) + pow((y_i-y_j),2)),3));
      }
    }

    if(m_P[i].get_name() != "Sun"){
      m_P[i].set_x(x_i  + vx*dt   + (1/2)*ax*dt*dt);
      m_P[i].set_vx(vx  + ax*dt);
      m_P[i].set_y(y_i  + vy*dt + (1/2)*ay*dt*dt);
      m_P[i].set_vy(vy  + ay*dt);
    }
  }
}


  
vector<Planet> System::get_Planets(){
  return m_P;
}







