#include "Planet.h"
#include <vector>
#ifndef SYSTEM
#define SYSTEM

class System{
  public:
  System();                       //Creates system with unnamed planet at the origin
  System(vector<Planet> P);       //Creates system with different planets from Planet vector input
  void Evolve(double dt);         //Evolves the system in time (using a given timestep dt)
  vector<Planet> get_Planets();   //Returns vector containing planet states





  private:
  vector<Planet> m_P;
};

#endif
