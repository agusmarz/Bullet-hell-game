#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
using namespace std;
using namespace sf;
class disparo {
public:
	disparo(Vector2f pos);
	virtual ~disparo();
	virtual void actualizar()=0;
	virtual bool intersecta(Vector2f pos)=0;
	Vector2f ver_pos();
	void dibujar(RenderWindow &w);
	FloatRect getBounds();
	
	
protected:
	ConvexShape disp;
};

#endif

