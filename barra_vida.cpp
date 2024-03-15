#include "barra_vida.h"
#include "barrita.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Barra_vida::Barra_vida(float width, float height,float startX, float startY, int pts_vida) : vida(pts_vida) {
	for(int i = 0; i < vida; i++){
		Barrita nueva(width ,height, vida,i+1,startX, startY);
		barra_vida.push_back(nueva);
	}
	rect.setSize(sf::Vector2f(width, height));
	rect.setPosition(startX, startY);
	rect.setFillColor({232, 233, 233,255});
}

void Barra_vida::quitar_vida(){
	barra_vida[vida-1].recolor();
	vida--;
}

void Barra_vida::actualizar(Vector2f pos){
	auto perimetro = rect.getGlobalBounds();
	pos.x -= perimetro.width /2.f;
	for(auto &x: barra_vida) x.actualizar(pos);
	rect.setPosition(pos);
}

void Barra_vida::dibujar(RenderWindow &w){
	w.draw(rect);
	for(auto &x : barra_vida) x.dibujar(w);
};
