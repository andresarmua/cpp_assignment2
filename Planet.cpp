#include <string>
#include "Planet.h"

using namespace std;




int Planet::m_counter = 0;




Planet::Planet() {

  m_name      = "NULL";
  m_mass      = 0;
  m_x         = 0;  
  m_y         = 0;
  m_vx        = 0;
  m_vy        = 0;

  m_counter++;
}




Planet::Planet(string name, double mass, double x, double y, double vx, double vy) {

  m_name      = name;
  m_mass      = mass;
  m_x         = x;
  m_y         = y; 
  m_vx        = vx;
  m_vy        = vy;

  m_counter++;
}


Planet::~Planet(){
  m_counter--;

}



string Planet::get_name() {
  return m_name;
}

double Planet::get_mass() {
  return m_mass;
}

double Planet::get_x() {
  return m_x;
}

double Planet::get_y() {
  return m_y;
}

double Planet::get_vx() {
  return m_vx;
}

double Planet::get_vy() {
  return m_vy;
}



void Planet::set_name(string name) {
  m_name = name;
}

void Planet::set_mass(double mass) {
  m_mass = mass;
}

void Planet::set_x(double x) {
  m_x = x;
}

void Planet::set_y(double y) {
  m_y = y;
}

void Planet::set_vx(double vx) {
  m_vx = vx;
}

void Planet::set_vy(double vy) {
  m_vy = vy;
}



void Planet::Evolve(double dt, double ax, double ay) {
  m_x   = m_x   + m_vx*dt + (1/2)*ax*dt*dt;
  m_vx  = m_vx  + ax*dt;
  m_y   = m_y   + m_vy*dt + (1/2)*ay*dt*dt;
  m_vy  = m_vy  + ay*dt;
}



int Planet::totalPlanets(){
  return m_counter;
}
