#include "esqueleto_.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "esqueletito_.h"
#include "disparo_esqueleto.h"
#include <iostream>
#include "alien.h"
#include "GLobal.h"

using namespace std;

esqueleto_::esqueleto_(int cadencia, int tiempo_spawn, float potencia_disp, int ptos_vida, sf::Time global)
	: Enemigo(cadencia, 20, tiempo_spawn, potencia_disp, 100, 20, 0, 0, ptos_vida, 1, global),
	centro_izq(10), centro_der(10), outerCircle2(28), outerCircle1(28)
{
	
	centro_der.setPosition(508, -51);
	
	centro_izq.setPosition(322, -51);
	centro_der.setFillColor(Color::Red);
	centro_izq.setFillColor(Color::Red);
	
	s_cabeza.setOrigin(250, 300);
	s_cabeza.scale(0.7, 0.7);
	s_cabeza.setPosition(320, 50);
	s_cabeza.setTexture(*seleccionador_textur(12));
	
	s_mano_der.setPosition(120, 0);
	s_mano_der.rotate(-40);
	s_mano_der.setOrigin(250, 160);
	s_mano_der.setTexture(*seleccionador_textur(10));
	s_mano_der.scale(0.5, 0.5);
	
	s_mano_izq.setOrigin(100, 160);
	s_mano_izq.rotate(40);
	s_mano_izq.scale(0.5, 0.5);
	s_mano_izq.setPosition(670, 0);
	s_mano_izq.setTexture(*seleccionador_textur(11));
	velocidad.x = 0.5;
	velocidad.y = 0.5;
	outerCircle2.setPosition(320, 45);
	outerCircle1.setPosition(508, 45);
	vida_max = ptos_vida;
	angle_movimiento = 0;
	b_cambio = true;
	buffer_disparo2 = *seleccionador_son(10);
	sonido_disparo2.setBuffer(buffer_disparo2);
	c_cambio = 0;
}

esqueleto_::~esqueleto_()
{
	if (sonido_disparo2.getStatus() == Sound::Playing)
	{
		sonido_disparo2.stop();
	}
}

vector<particula_explo> esqueleto_::explocion()
{
	vector<particula_explo> pe;
	Vector2f aux;
	for (int i = 0; i < 10; i++)
	{
		aux = s_cabeza.getPosition();
		aux.x += (rand() % 50 - 25);
		particula_explo p(139, 0, 0, aux);
		pe.push_back(p);
	}
	return pe;
}

void esqueleto_::actualizar(Vector2f pos_na, sf::Time global)
{
	double aux_espera_time = global.asMilliseconds() - espera;
	if (aux_espera_time > tiempo_spawn)
	{
		if (b_cambio)
		{
			centro_der.setFillColor(Color::Red);
			centro_izq.setFillColor(Color::Red);
		}
		else
		{
			centro_der.setFillColor(Color::Yellow);
			centro_izq.setFillColor(Color::Yellow);
		}
		angle_movimiento += 0.1;
		s_mano_der.setPosition(120 + 20 * cos(angle_movimiento), 150 + 20 * sin(angle_movimiento));
		s_mano_izq.setPosition(670 + 20 * cos(-angle_movimiento), 150 + 20 * sin(-angle_movimiento));
		
		Vector2f angder = pos_na - centro_der.getPosition();
		Vector2f angizq = pos_na - centro_izq.getPosition();
		
		float longitud1 = sqrt((angder.x * angder.x) + (angder.y * angder.y));
		float longitud2 = sqrt((angizq.x * angizq.x) + (angizq.y * angizq.y));
		angder /= longitud1;
		angizq /= longitud2;
		centro_der.move(angder * 5.f);
		centro_izq.move(angizq * 5.f);
		
		sf::Vector2f distanceVec = centro_der.getPosition() - outerCircle1.getPosition();
		float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
		if (distance > outerCircle1.getRadius() - centro_der.getRadius())
		{
			
			centro_der.setPosition(outerCircle1.getPosition() + distanceVec / distance * (outerCircle1.getRadius() - centro_der.getRadius()));
		}
		
		distanceVec = centro_izq.getPosition() - outerCircle2.getPosition();
		distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
		if (distance > outerCircle2.getRadius() - centro_izq.getRadius())
		{
			
			centro_izq.setPosition(outerCircle2.getPosition() + distanceVec / distance * (outerCircle2.getRadius() - centro_izq.getRadius()));
		}
		
		if (s_cabeza.getPosition().x > 328 || s_cabeza.getPosition().x < 310)
		{
			velocidad.x = velocidad.x * -1;
		}
		if (s_cabeza.getPosition().y > 159 || s_cabeza.getPosition().y < 140)
		{
			velocidad.y = velocidad.y * -1;
		}
		
		s_cabeza.move(velocidad);
		outerCircle1.move(velocidad);
		outerCircle2.move(velocidad);
		centro_der.move(velocidad);
		centro_izq.move(velocidad);
	}
	else
	{
		if (s_cabeza.getPosition().y < 150)
		{
			s_cabeza.move(0, 1.5);
			centro_der.move(0, 1.5);
			centro_izq.move(0, 1.5);
		}
		if (s_mano_der.getPosition().y < 150)
		{
			s_mano_der.move(0, 2);
			s_mano_izq.move(0, 2);
		}
	}
}
void esqueleto_::detener_sonido(){
	if(sonido_disparo.getStatus() == Sound::Playing){
		sonido_disparo.stop();
	}
	if(sonido_disparo2.getStatus() == Sound::Playing){
		sonido_disparo2.stop();
	}
}
bool esqueleto_::le_dispararon (disparo * nalf) {
	Vector2f p=s_cabeza.getPosition()-nalf->ver_pos();
	Vector2f i=s_mano_izq.getPosition()-nalf->ver_pos();
	Vector2f d=s_mano_der.getPosition()-nalf->ver_pos();
	if(sqrt((p.x-10*p.x-10)/10+(p.y*p.y))<40
	   ||sqrt( (d.x*d.x)+d.y*d.y)<50
		||sqrt(i.x*i.x+i.y*i.y)<50 )return true;
	else return false;
	
}

void esqueleto_::dibujar (RenderWindow & w) {
	w.draw(s_cabeza);
	w.draw(s_mano_der);
	w.draw(s_mano_izq);
	w.draw(centro_der);
	w.draw(centro_izq);
	bar_vida.dibujar(w);
}


vector<disparo*> esqueleto_::generardisparo (Vector2f pos_nave) {
		c_cambio++;
		cout<<c_cambio<<endl;
		if((!b_cambio && c_cambio>45)||(b_cambio && c_cambio>2)){

		if(rand()%3<2){
			b_cambio=true;
		}
		else{
			b_cambio=false;
		}
		c_cambio=0;
		}
	vector <disparo*> disparos;
	int aux=vida_max/2;
	if(b_cambio){
		sonido_disparo.play();
		if(vida==aux){
			disparos.push_back(new esqueletito_(50,10,0,0,1,s_mano_der.getPosition(),potencia_disp));
			disparos.push_back(new esqueletito_(50,10,0,0,1,s_mano_izq.getPosition(), potencia_disp));
			return disparos;
		}
		else{
			disparos.push_back(new esqueletito_(50,10,0,0,2,s_mano_der.getPosition(),potencia_disp));
			disparos.push_back(new esqueletito_(50,10,0,0,2,s_mano_izq.getPosition(),potencia_disp));
			return disparos;
		}
		
	}
	else{		
		Vector2f pos1=s_cabeza.getPosition();
		pos1.x=pos1.x+120;
		Vector2f pos2=s_cabeza.getPosition();
		pos2.x=pos2.x+90;
		if (sonido_disparo2.getStatus() != Sound::Playing)
		{
			sonido_disparo2.play();
		}
		
		disparos.push_back(new disparo_esqueleto(pos1));
		disparos.push_back(new disparo_esqueleto(pos2));
		return disparos;
	}
}
void esqueleto_::restart_clock(sf::Time global)
{
	disp_clock = global.asMilliseconds();
	espera = global.asMilliseconds();
	c_cambio = 0;
}
bool esqueleto_::debedisparar(sf::Time global)
{
	
	double aux_espera_time = global.asMilliseconds() - espera;
	if (aux_espera_time < tiempo_spawn)
		return false;
	double aux_disp_time = global.asMilliseconds() - disp_clock;
	if (b_cambio && aux_disp_time < cadencia)
	{
		return false;
	}
	if (c_cambio < 60 && aux_disp_time < 100)
	{
		return false;
	}
	disp_clock = global.asMilliseconds();
	return true;
}
