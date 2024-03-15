#include "escopeta.h"
#include "disparo_escopeta.h"
#include <cmath>
#include <fstream>
using namespace std;
Escopeta::Escopeta(float pos_x, float pos_y, float m_cadencia, float m_velocidad_movimiento, int m_tiempo_spawn, float m_potencia_disp, int ptos_vida,Time global): Proletario(pos_x, pos_y,m_cadencia, m_velocidad_movimiento,  m_tiempo_spawn, m_potencia_disp, ptos_vida,3,global){	
	
}

vector<disparo*> Escopeta::generardisparo(Vector2f pos_nave) {
	Vector2f pos_enemigo = nave.getPosition();
	vector<disparo*> v;
	pos_nave.x +=50;
	for(int i = 0; i < 3 ; i++){
		v.push_back(new disparo_escopeta(pos_enemigo,pos_nave, potencia_disp));
		pos_nave.x -=50;
	}
	return v;
}

