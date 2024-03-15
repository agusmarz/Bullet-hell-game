#include "disparoNave.h"
using namespace sf;
disparoNave::disparoNave(Vector2f pos):disparo(pos) {
	disp.setPointCount(8);
	disp.setPoint(0, sf::Vector2f(10, 0));
	disp.setPoint(1, sf::Vector2f(90, 0));
	disp.setPoint(2, sf::Vector2f(100, 10));
	disp.setPoint(3, sf::Vector2f(100, 190));
	disp.setPoint(4, sf::Vector2f(90, 200)); 
	disp.setPoint(5, sf::Vector2f(10, 200));
	disp.setPoint(6, sf::Vector2f(0, 190)); 
	disp.setPoint(7, sf::Vector2f(0, 10));
	disp.scale(0.1,0.1);
	disp.setFillColor(Color::Red);
};
 bool disparoNave::intersecta(Vector2f pos){
	 return false;
 }
	

void disparoNave::actualizar(){
	disp.move(0,-8);
}
