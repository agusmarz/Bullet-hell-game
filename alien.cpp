#include "alien.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include "GLobal.h"
using namespace std;

alien::alien(float m_cadencia, int m_tiempo_spawn, float m_potencia_disp, int ptos_vida, Time global) : Enemigo(m_cadencia, 2, m_tiempo_spawn, m_potencia_disp, 100, 30, 0, 0, ptos_vida, 0, global) {
	
	s_alien.setOrigin(430, 180);
	s_alien.scale(0.7, 0.7);
	s_alien.setPosition(400, -50);
	s_turbina1.setPosition(20, -50);
	s_turbina1.setOrigin(150, 150);
	s_turbina2.setOrigin(150, 150);
	s_turbina1.scale(0.5, 0.5);
	s_turbina2.scale(0.5, 0.5);
	s_turbina2.setPosition(750, -50);
	s_alien.setTexture(*seleccionador_textur(0));
	s_turbina1.setTexture(*seleccionador_textur(1));
	s_turbina2.setTexture(*seleccionador_textur(1));
}

vector<particula_explo> alien::explocion() {
	vector<particula_explo> pe;
	Vector2f aux;
	for (int i = 0; i < 10; i++) {
		aux = s_alien.getPosition();
		aux.x += (rand() % 50 - 25);
		particula_explo p(40, 114, 51, aux);
		pe.push_back(p);
	}
	return pe;
}

void alien::actualizar(Vector2f pos_na, Time global) {
	double aux_espera_time = global.asMilliseconds() - espera;
	if (aux_espera_time > tiempo_spawn) {
		Vector2f pos_enemigo = s_alien.getPosition();
		Vector2f ang_turbina1 = pos_na - s_turbina1.getPosition();
		Vector2f ang_turbina2 = pos_na - s_turbina2.getPosition();
		float grado_turbina1 = 280+atan2(ang_turbina1.y, ang_turbina1.x) * 180 / 3.14159265;
		float grado_turbina2 = 280+atan2(ang_turbina2.y, ang_turbina2.x) * 180 / 3.14159265;
		
		s_turbina1.setRotation(grado_turbina1);
		s_turbina2.setRotation(grado_turbina2);
		if( s_alien.getPosition().x<390|| s_alien.getPosition().x<380){
			pos_enemigo.x -= velocidad_movimiento;
		}
		if(s_alien.getPosition().y>15|| s_alien.getPosition().y<-5){
			pos_enemigo.y -= velocidad_movimiento;
		}
		s_alien.setPosition(pos_enemigo);
		//
	}
	else{
		if(s_alien.getPosition().y<10){
			s_alien.move(0,0.5);
		} 
		if(s_turbina1.getPosition().y<50){
			s_turbina1.move(0,2);s_turbina2.move(0,2);
		}
	}

}
vector<disparo*> alien::generardisparo(Vector2f pos_nave){
	Vector2f pos1=s_turbina1.getPosition();
	
	Vector2f dir1=pos1-pos_nave;
	float longitud1 = sqrt((dir1.x * dir1.x) + (dir1.y * dir1.y));
	if (longitud1 != 0) {
		dir1 /= longitud1;
	}
	Vector2f pos2=s_turbina2.getPosition();
	Vector2f dir2=pos2-pos_nave;
	float longitud2 = sqrt((dir2.x * dir2.x) + (dir2.y * dir2.y));
	if (longitud2 != 0) {
		dir2 /= longitud2;
	}
	//disparo *aux1= new disparo_alien(pos1,dir1);
	//disparo *aux2= new disparo_alien(pos2,dir2);
	vector<disparo*> v;
	v.push_back(new disparo_alien(pos1,dir1,potencia_disp));
	v.push_back(new disparo_alien(pos2,dir2, potencia_disp));
	return v;
}

void alien::dibujar(RenderWindow &w){
	w.draw(s_alien);
	w.draw(s_turbina1);
	w.draw(s_turbina2);
	dibujar_barra(w);
}
bool alien::le_dispararon(disparo* nalf){
	Vector2f p=nalf->ver_pos();
	
	if(p.y<8)return true;
	else return false;
}


