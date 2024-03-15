#ifndef BARRA_VIDA_H
#define BARRA_VIDA_H
#include <SFML/Graphics/RectangleShape.hpp>
#include "barrita.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Barra_vida{
	vector<Barrita> barra_vida;
	int vida;
	RectangleShape rect;
public:
	Barra_vida(float width, float height,float startX, float startY, int ptos_vida);
	void quitar_vida();
	void dibujar(RenderWindow &w);
	void actualizar(Vector2f pos);
};


#endif
