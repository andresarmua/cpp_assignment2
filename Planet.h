/*0. 

Create a class Planet that has the data members of name (type string), mass and distance (type double). Create this in its own separate files (.cc and .h) and define member setter and getter functions for each of the data members.

*/


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
