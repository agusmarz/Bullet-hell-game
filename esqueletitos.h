#ifndef ESQUELETITOS_H
#define ESQUELETITOS_H
#include "enemigo.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
class esqueletitos : public Enemigo {
public:
	esqueletitos(float width, float height,float startX, float startY, int ptos_vida,Vector2f pos);
	bool le_dispararon (disparo * nalf);
	void dibujar (RenderWindow & w);
	void actualizar (Vector2f pos_na);
private:
	Clock cambio;
	Texture t_esq1,t_esq2;
	Sprite s_esqueletito;
	bool flag;
};

#endif

