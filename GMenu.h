#ifndef GMENU_H
#define GMENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Partida.h"
#include "Scene.h"
#include "Game.h"
#include "fondo_p.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
using namespace sf;
class GMenu : public Scene{
public:
	GMenu(bool _estado);
	void Draw(RenderWindow &w) override;
	void Update(Game &game) override;
	
private:
	Sprite s_arrow;
	Sprite s_3bits;
	Sprite s_youwin;
	Sprite s_youlose;
	Sprite elec;
	fondo_p fondo;
	Text menu, reiniciar;
	Vector2f escalas;
	bool estado;
	SoundBuffer buffer_perdiste;
	Sound s_perdiste;
	SoundBuffer buffer_ganaste;
	Sound s_ganaste;
};

#endif

