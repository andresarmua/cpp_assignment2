#include <string>
#include "Planet.h"

using namespace std;

Planet::Planet() {

  m_name      = "NULL";
  m_mass      = 0;
  m_x         = 0;  
//  m_y         = 0;
//  m_vx        = 0;
//  m_vy        = 0;

}

Planet::Planet(string name, double mass, double x) {

  m_name      = name;
  m_mass      = mass;
  m_x         = x;
//  m_y         = 0;
//  m_vx        = 0;
//  m_vy        = 0;

}


//Planet::Planet(string name, double mass, double x, double y, double vx, double vy) {

 // m_name      = name;
  //m_mass      = mass;
  //m_x         = x;
//  m_y         = y; 
//  m_vx        = vx;
//  m_vy        = vy;

//}


string Planet::get_name() {
  return m_name;
}

double Planet::get_mass() {
  return m_mass;
}

double Planet::get_x() {
  return m_x;
}

//double Planet::get_y() {
//  return m_y;
//}

//double Planet::get_vx() {
//  return m_vx;
//}

//double Planet::get_vy() {
//  return m_vy;
//}


void Planet::set_name(string name) {
  m_name = name;
}

void Planet::set_mass(double mass) {
  m_mass = mass;
}

void Planet::set_x(double x) {
  m_x = x;
}

//void Planet::set_y(double y) {
//  m_y = y;
//}

//void Planet::set_vx(double vx) {
//  m_vx = vx;
//}

//void Planet::set_vy(double vy) {
//  m_vy = vy;
//}
