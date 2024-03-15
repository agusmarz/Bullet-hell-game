#include "disparo_alien.h"
#include <cmath>
using namespace std;

disparo_alien::disparo_alien(Vector2f pos,Vector2f dir, float potencia_disp):disparo(pos) {
	disp.setPointCount(8);
	disp.setPoint(0, sf::Vector2f(50, 50));
	disp.setPoint(1, sf::Vector2f(150, 50));
	disp.setPoint(2, sf::Vector2f(200, 100));
	disp.setPoint(3, sf::Vector2f(200, 200));
	disp.setPoint(4, sf::Vector2f(150, 250));
	disp.setPoint(5, sf::Vector2f(50, 250));
	disp.setPoint(6, sf::Vector2f(0, 200));
	disp.setPoint(7, sf::Vector2f(0, 100));
	disp.setFillColor(sf::Color::Green);
	float midX = (disp.getPoint(0).x + disp.getPoint(4).x) / 2;
	float midY = (disp.getPoint(0).y + disp.getPoint(4).y) / 2;
	disp.setOrigin(midX, midY);
	
	
	disp.scale(0.3,0.3);
	vel_disp=dir*potencia_disp;
	
}
bool disparo_alien::intersecta(Vector2f pos){
Vector2f pos_na=pos;
Vector2f pos_disp=disp.getPosition();
float dist=sqrt((pos_na.x-pos_disp.x)*(pos_na.x-pos_disp.x)+(pos_na.y-pos_disp.y)/2*(pos_na.y-pos_disp.y)/2);
if(dist<25) return true;
else return false;
}
void disparo_alien::actualizar(){
	disp.move(-vel_disp);
}



