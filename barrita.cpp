#include "barrita.h"
Barrita::Barrita(float width, float height, int cant_bars, int pos, float startX, float startY){
	margen_x = width * 0.02;
	width = (width -margen_x*2) / cant_bars;
	margen_y = height * 0.05;
	m_width = width;
	rect.setSize(sf::Vector2f(m_width, height - margen_y*2));
	nro_bar = pos;
	
	rect.setFillColor({62, 255, 0, 255});
	rect.setPosition(sf::Vector2f(margen_x + startX + m_width*(pos-1), startY+margen_y));
	
}
void Barrita::actualizar(Vector2f pos){
	rect.setPosition(sf::Vector2f(margen_x + pos.x + m_width*(nro_bar-1), pos.y+margen_y));
}
void Barrita::recolor(){
	rect.setFillColor({255, 0, 0,255});
}

void Barrita::dibujar(RenderWindow &w){
	w.draw(rect);
}
