
#include <string>

#ifndef PLANET
#define PLANET

using namespace std;

class Planet {
	
	public:
	
	Planet();
	Planet(string name, double mass, double x, double y, double vy, double vx);
    ~Planet();
    void set_name(string name);
    void set_mass(double mass);
	void set_x(double x);
	void set_y(double x);
	void set_vx(double x);
	void set_vy(double x);
    static int totalPlanets();

      
    string get_name();
    double get_mass();
    double get_x(); 
    double get_y(); 
    double get_vx(); 
    double get_vy(); 
   
    void Evolve(double dt, double ax, double ay);   
   


	private:
	
	string m_name;
	double m_mass;
    double m_x;
    double m_y;
    double m_vx;
    double m_vy;
    static int m_counter;


};  // is this ';' necessary?


#endif



