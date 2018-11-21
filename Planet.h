
#include <string>

#ifndef PLANET
#define PLANET

using namespace std;

class Planet {
	
	public:
	
	Planet();
	Planet(string name, double mass, double x);
    void set_name(string name);
    void set_mass(double mass);
	void set_x(double x);

      
    string get_name();
    double get_mass();
    double get_x(); 
   
   
   


	private:
	
	string m_name;
	double m_mass;
    double m_x;


};  // is this ';' necessary?


#endif



