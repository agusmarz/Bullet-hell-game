#ifndef MENUCONFIG_H
#define MENUCONFIG_H
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>

class MenuConfig : public Scene {
public:
	MenuConfig();
	void Draw (RenderWindow & w);
	void Update (Game & game);
private:
	fondo_p fondo;	
	Sprite s_arrow;
	Sprite s_proletario;
	Sprite s_alien;
	Sprite s_esqueleto;
	Text volver;
	Text seleccion;
	RectangleShape rectangulito;
	Clock clock;
	double sleeptime;
	double time;
};

#endif

