#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include "disparo.h"
#include "barra_vida.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <string>
#include "particula_explo.h"
#include <SFML/System/Time.hpp>
using namespace std;
using namespace sf;
class Enemigo{
public:
	Enemigo(float m_cadencia, float m_velocidad_movimiento, int m_tiempo_spawn, float m_potencia_disp, float width, float height,float startX, float startY, int ptos_vida, int selec_sonido,Time global);
	
	virtual ~Enemigo();
	
	void perdio_vida() ;
	int ver_vida();
	void restart_clock(Time global);
	
	void dibujar_barra(RenderWindow &w);
	virtual bool debedisparar(Time global);
	virtual void detener_sonido();
	virtual bool le_dispararon(disparo *nalf) = 0;
	virtual void dibujar(RenderWindow &w) = 0 ;
	virtual void actualizar(Vector2f pos_na,Time global)= 0 ;
	virtual vector<disparo*> generardisparo(Vector2f pos_nave)= 0 ;
	virtual vector<particula_explo> explocion() = 0;
	
protected:
	Sound sonido_disparo; 
	SoundBuffer buffer_disparo;
	int vida, tiempo_spawn;
	Barra_vida bar_vida;
	float velocidad_movimiento, cadencia, potencia_disp;
	double disp_clock, espera;
};
#endif


