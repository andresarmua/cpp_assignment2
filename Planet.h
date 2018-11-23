
#include <string>

#ifndef PLANET
#define PLANET

using namespace std;

class Planet {
	
	public:
	
	Planet();
	Planet(string name, double mass, double x, double y, double vy, double vx);
    void set_name(string name);
    void set_mass(double mass);
	void set_x(double x);
	void set_y(double x);
	void set_vx(double x);
	void set_vy(double x);

      
    string get_name();
    double get_mass();
    double get_x(); 
    double get_y(); 
    double get_vx(); 
    double get_vy(); 
   
   
   


	private:
	
	string m_name;
	double m_mass;
    double m_x;
    double m_y;
    double m_vx;
    double m_vy;


};  // is this ';' necessary?


#endif



