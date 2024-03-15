#include "disparo_esqueleto.h"
#include <cmath>
using namespace std;

disparo_esqueleto::disparo_esqueleto(Vector2f pos):disparo(pos) {
	disp.setPointCount(8); // El número de lados
	
	float radius = 100.f;
	float pi = 3.14159265f;
	
	for (std::size_t i = 0; i < 8; ++i)
	{
		float angle = i * 2 * pi / 8 - pi / 2;
		float x = std::cos(angle) * radius;
		float y = std::sin(angle) * radius;
		disp.setPoint(i, sf::Vector2f(x, y));
	}
	disp.setOrigin(radius, radius);
	disp.scale(0.5,0.5);
	disp.setFillColor(Color::Cyan);
	disp.scale(1,1);
	disp.rotate(45);
}
bool disparo_esqueleto::intersecta(Vector2f pos){
	Vector2f pos_na=pos;
	Vector2f pos_disp=disp.getPosition();
	float dist=sqrt((pos_na.x-pos_disp.x)*(pos_na.x-pos_disp.x)+(pos_na.y-pos_disp.y)*(pos_na.y-pos_disp.y));
	if(dist<50) return true;
	else return false;
}
void disparo_esqueleto::actualizar ( ) {
	disp.move(0,9);
}

