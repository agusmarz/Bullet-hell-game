#ifndef BARRITA_H
#define BARRITA_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Barrita{
	RectangleShape rect;
	float margen_x, margen_y, m_width;
	int nro_bar;
public:
	Barrita(float width, float height, int cant_bars, int pos, float startX, float startY);
	void recolor();
	void dibujar(RenderWindow &w);
	void actualizar(Vector2f pos);
};
#endif
