#ifndef FONDO_P_H
#define FONDO_P_H
#include <vector>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;

class fondo_p {
public:
	fondo_p();
	void dibujar(RenderWindow &w);
private:
	vector<CircleShape> strellas;
};

#endif

