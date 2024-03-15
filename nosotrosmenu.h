#ifndef NOSOTROSMENU_H
#define NOSOTROSMENU_H
#include "Scene.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class nosotrosmenu : public Scene {
public:
	nosotrosmenu();
	void Draw (RenderWindow & w);
	void Update (Game & game);
private:
	Text textito;
	Text textito2;
	Sprite foto;
	SoundBuffer buffer_cancion;
	Sound cancion;
	
};

#endif

