#include "particula_explo.h"
#include <cstdlib>
#include <cmath>
using namespace std;

particula_explo::particula_explo(int R,int G,int B,Vector2f pos) {
	float ancho = 50.0f;
	float altura = 75.0f;
	particula.setSize(sf::Vector2f(ancho, altura));
	particula.setFillColor(Color(R,G,B));
	particula.scale(0.5,0.5);
	particula.setPosition(pos);
	float angulo = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(2*M_PI));
	
	// Calcula las componentes x e y de la dirección
	dir.x = cos(angulo)*5;
	dir.y = sin(angulo);
}
bool particula_explo::eliminar(){
	Vector2f p=particula.getPosition();
	if((p.x<0 || p.x>820)||(p.y<0 || p.y>620)) {
		return true;
	} else {
		return false;
	}
}
void particula_explo::actualizar(){
	dir.y+=0.2;
	particula.move(dir);
}
void particula_explo::dibujar(RenderWindow &w){
	w.draw(particula);
}
