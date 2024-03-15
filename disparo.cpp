#include "disparo.h"
#include <iostream>
using namespace std;

disparo::disparo(Vector2f pos) {
	disp.setPosition(pos);
}

Vector2f disparo::ver_pos(){
	return(disp.getPosition());
}
void disparo::dibujar(RenderWindow &w){
	w.draw(disp);
}
FloatRect disparo::getBounds(){
	return disp.getGlobalBounds();
}
disparo::~disparo() {

}
