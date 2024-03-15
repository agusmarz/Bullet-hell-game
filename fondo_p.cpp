#include "fondo_p.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;
fondo_p::fondo_p() {
	for (int i=0;i<60;i++){
		Vector2f x;
		x.x=rand()%801;
		x.y=rand()%601;
		CircleShape circ;
		circ.setPosition(x);
		circ.setRadius(2);
		circ.setOrigin(2,2);
		circ.setFillColor({255,255,255});
		strellas.push_back(circ);
	}
}
void fondo_p::dibujar(RenderWindow &w){
	for(auto &x:strellas){
		Vector2f aux;
		aux.x=x.getPosition().x;
		aux.y=5+x.getPosition().y;
		x.setPosition(aux);
		w.draw(x);
		if(x.getPosition().y>600){
			aux.x=rand()%801;
			aux.y=0;
			x.setPosition(aux);
		}
	}
}

