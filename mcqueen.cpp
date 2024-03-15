#include "mcqueen.h"
#include "disparo_alien.h"
#include <cmath>
#include <iostream>
#include "disparo_escopeta.h"
#include "disparo_raptor.h"
#include "disparo_mcqueen.h"
#include <fstream>
#include "GLobal.h"

using namespace std;

Mcqueen::Mcqueen(float pos_x, float pos_y, float m_cadencia, float m_velocidad_movimiento, int m_tiempo_spawn, float m_potencia_disp, int ptos_vida,Time global): Proletario(pos_x, pos_y,m_cadencia, m_velocidad_movimiento,  m_tiempo_spawn, m_potencia_disp, ptos_vida,4,global){
	buffer_disparo_fin = *seleccionador_son(8);
	sonido_disparo_fin.setBuffer(buffer_disparo_fin);
}

vector<disparo*> Mcqueen::generardisparo(Vector2f pos_nave) {
	Vector2f pos_enemigo=nave.getPosition();
	
	vector<disparo*> v (1, new disparo_mcqueen(pos_enemigo,pos_nave,  potencia_disp));
	return v;
}


bool Mcqueen::debedisparar(sf::Time global) {
	int	 aux_disp_time = global.asMilliseconds();
	cout<<aux_disp_time<<endl;
	int cad=cadencia;
	float resto=aux_disp_time%(cad*2);
	if (resto < cadencia) {
		if (sonido_disparo.getStatus() == Sound::Playing) {
			sonido_disparo.stop();
			sonido_disparo_fin.play();
		}
		return false;
	}
	
	double aux_espera_time = global.asMilliseconds() - espera;
	if (aux_espera_time < tiempo_spawn)return false;
	
	
	if (sonido_disparo.getStatus() != Sound::Playing) {
		if (sonido_disparo_fin.getStatus() == Sound::Playing) {
			sonido_disparo_fin.stop();
		}
		sonido_disparo.play();
	}
	return true;
}

