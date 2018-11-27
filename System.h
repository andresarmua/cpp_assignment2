#include "Planet.h"
#include <vector>
#ifndef SYSTEM
#define SYSTEM

class System{
  public:
  System();
  System(vector<Planet> P);  
  void Evolve(double dt);
  vector<Planet> get_Planets();





  private:
  vector<Planet> m_P;
};







#endif
