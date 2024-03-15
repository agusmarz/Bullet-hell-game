#ifndef DISPARO_ALIEN_H
#define DISPARO_ALIEN_H
#include "disparo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <ctime>
using namespace std;
using namespace sf;
class disparo_alien:public disparo{
public:
	disparo_alien(Vector2f pos,Vector2f dir, float potencia_disp);
	void actualizar();
	virtual bool intersecta(Vector2f pos)override;
private:
	Vector2f vel_disp;
};

#endif

