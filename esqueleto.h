#ifndef ESQUELETO_H
#define ESQUELETO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include "enemigo.h"
using namespace sf;
class esqueleto : public Enemigo {
public:
	esqueleto(float width, float height,float startX, float startY, int ptos_vida);
private:
	Texture t_mano_izq,t_mano_der,t_cabeza;
	Sprite s_mano_izq,s_mano_der,s_cabeza;
	Clock espera;
};

#endif

