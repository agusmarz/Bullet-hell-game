#include "enemigo.h"
#include "barra_vida.h"
#include "GLobal.h"
#include <iostream>

using namespace std;

Enemigo::Enemigo(float m_cadencia, float m_velocidad_movimiento, int m_tiempo_spawn, float m_potencia_disp, float width, float height, float startX, float startY, int ptos_vida, int selec_sonido, sf::Time global)
	: bar_vida(width, height, startX, startY, ptos_vida)
{
	vida = ptos_vida;
	tiempo_spawn = m_tiempo_spawn;
	cadencia = m_cadencia;
	velocidad_movimiento = m_velocidad_movimiento;
	potencia_disp = m_potencia_disp;
	buffer_disparo = *seleccionador_son(selec_sonido);
	sonido_disparo.setBuffer(buffer_disparo);
	disp_clock = global.asMilliseconds();
	espera = global.asMilliseconds();
}

void Enemigo::restart_clock(sf::Time global)
{
	disp_clock = global.asMilliseconds();
	espera = global.asMilliseconds();
}

void Enemigo::perdio_vida()
{
	vida--;
	bar_vida.quitar_vida();
	return;
}
void Enemigo::detener_sonido(){
	if(sonido_disparo.getStatus() == Sound::Playing){
		sonido_disparo.stop();
	}
}
int Enemigo::ver_vida()
{
	return vida;
}

void Enemigo::dibujar_barra(RenderWindow &w)
{
	bar_vida.dibujar(w);
}

bool Enemigo::debedisparar(sf::Time global)
{
	double aux_disp_time = global.asMilliseconds() - disp_clock;
	if (aux_disp_time < cadencia)
		return false;
	double aux_espera_time = global.asMilliseconds() - espera;
	if (aux_espera_time < tiempo_spawn)
		return false;
	disp_clock = global.asMilliseconds();
	sonido_disparo.play();
	return true;
}

Enemigo::~Enemigo()
{
	if (sonido_disparo.getStatus() == Sound::Playing)
	{
		sonido_disparo.stop();
	}
}

