#ifndef ALIEN_H
#define ALIEN_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include "disparo_alien.h"
#include "barra_vida.h"
#include "enemigo.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "particula_explo.h"
#include <SFML/System/Time.hpp>
using namespace sf;

class alien : public Enemigo{
public:
	alien( float m_cadencia, int m_tiempo_spawn, float m_potencia_disp,int ptos_vida,Time global);
	
	virtual void dibujar(RenderWindow &w) override;
	virtual void actualizar(Vector2f pos_na,Time global) override;
	virtual vector<disparo*> generardisparo(Vector2f pos_nave) override;
	virtual bool le_dispararon(disparo *nalf) override;
	virtual vector<particula_explo> explocion() override;
	
private:
	
	Sprite s_turbina1,s_turbina2,s_alien;
	
};

#endif

