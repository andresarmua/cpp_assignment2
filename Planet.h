
#include <string>

#ifndef PLANET
#define PLANET

using namespace std;

class Planet {
	
	public:
	
	//Planet constructors

    Planet();        	
    Planet(string name, double mass, double x, double y, double vy, double vx);
    ~Planet();
    //Set Functions

    void set_name(string name);
    void set_mass(double mass);
	void set_x(double x);
	void set_y(double x);
	void set_vx(double x);
	void set_vy(double x);

    //Returns number of planets created
    static int totalPlanets();

    //Get Functions 
    string get_name();
    double get_mass();
    double get_x(); 
    double get_y(); 
    double get_vx(); 
    double get_vy(); 
   
    void Evolve(double dt, double ax, double ay);   
   


	private:
	
	string m_name;          // Planet name
	double m_mass;          // Planet mass
    double m_x;             // Planet x coordinate
    double m_y;             // Planet y coordinate
    double m_vx;            // Planet x velocity
    double m_vy;            // Planet y velocity
    static int m_counter;   // Planet counter


};  // is this ';' necessary?


#endif



