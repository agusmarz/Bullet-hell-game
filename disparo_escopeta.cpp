#include "disparo_escopeta.h"
#include <cmath>
using namespace std;
disparo_escopeta::disparo_escopeta(Vector2f pos,Vector2f dir, float potencia_disp):disparo(pos) {
	disp.setPointCount(4);
	disp.setPoint(0, sf::Vector2f(0, 0));
	disp.setPoint(1, sf::Vector2f(100, 0));
	disp.setPoint(2, sf::Vector2f(100, 100));
	disp.setPoint(3, sf::Vector2f(0, 100));
	
	disp.setFillColor(sf::Color::Blue);
	
	disp.scale(0.2,0.2);
	
	
	vel_disp=dir-pos;
	float length = std::sqrt(vel_disp.x * vel_disp.x + vel_disp.y * vel_disp.y);
	if (length != 0) {
		vel_disp /= length;
	}
	
	vel_disp *= potencia_disp;
}
void disparo_escopeta::actualizar(){
	
	disp.move(vel_disp);
}

bool disparo_escopeta::intersecta(Vector2f pos){
	Vector2f pos_na=pos;
	Vector2f pos_disp=disp.getPosition();
	float dist=sqrt((pos_na.x-pos_disp.x)*(pos_na.x-pos_disp.x)+(pos_na.y-pos_disp.y)/2*(pos_na.y-pos_disp.y)/2);
	if(dist<10) return true;
	else return false;
}
