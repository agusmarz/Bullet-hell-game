
#include "disparo_raptor.h"
#include <iostream>
#include <cmath>
using namespace std;
disparo_raptor::disparo_raptor(Vector2f pos,Vector2f dir, float potencia_disp):disparo(pos) {
	disp.setPointCount(5);
	disp.setPoint(0, sf::Vector2f(50, 0));
	disp.setPoint(1, sf::Vector2f(100, 40));
	disp.setPoint(2, sf::Vector2f(80, 100));
	disp.setPoint(3, sf::Vector2f(20, 100));
	disp.setPoint(4, sf::Vector2f(0, 40));
	
	disp.setFillColor(sf::Color::Green);
	
	disp.scale(0.2,0.2);
	
	vel_disp = dir-pos;
	
	float length = std::sqrt(vel_disp.x * vel_disp.x + vel_disp.y * vel_disp.y);
	if (length != 0) {
		vel_disp /= length;
	}
	
	vel_disp *= potencia_disp;
}

bool disparo_raptor::intersecta(Vector2f pos){
	Vector2f pos_na=pos;
	Vector2f pos_disp=disp.getPosition();
	float dist=sqrt((pos_na.x-pos_disp.x)*(pos_na.x-pos_disp.x)+(pos_na.y-pos_disp.y)*(pos_na.y-pos_disp.y));
	if(dist<20) return true;
	else return false;
}

void disparo_raptor::actualizar(){
	
	disp.move(vel_disp);
}
