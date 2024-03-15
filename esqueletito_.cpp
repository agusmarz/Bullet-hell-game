#include "esqueletito_.h"
#include <cmath>
#include "disparoNave.h"
#include <iostream>
#include "GLobal.h"
#include "particula_explo.h"
using namespace std;
esqueletito_::esqueletito_(float width, float height,float startX, float startY, int ptos_vida,Vector2f pos, float m_velocidad):Enemigo(0,m_velocidad,0,0,width,  height, startX,  startY,  ptos_vida,9,cambio.getElapsedTime()),disparo(pos){
	int eleccion=rand()%2;
	if(eleccion==0){
		s_esqueletito.setTexture(*seleccionador_textur(2));
		flag=true;
	}
	else{
		s_esqueletito.setTexture(*seleccionador_textur(3));
		flag=false;
	}
	s_esqueletito.scale(0.1,0.1);
	s_esqueletito.setPosition(pos);
	Vector2u textureSize = seleccionador_textur(3)->getSize();
	s_esqueletito.setOrigin(textureSize.x / 2, textureSize.y / 2);
	disp.setPointCount(4);
	float midX = (disp.getPoint(0).x+ disp.getPoint(2).x) / 2;
	float midY = (disp.getPoint(0).y + disp.getPoint(2).y) / 2;
	
	disp.setOrigin(midX, midY);
	disp.setPoint(0, sf::Vector2f(0, 0));
	disp.setPoint(1, sf::Vector2f(100, 0));
	disp.setPoint(2, sf::Vector2f(100, 100));
	disp.setPoint(3, sf::Vector2f(0, 100));
	
	// Hacer el cuadrado invisible
	disp.setFillColor(sf::Color::Transparent);
	disp.scale(0.1,0.1);
	Vector2f aux_pos=pos;
	aux_pos.x=aux_pos.x+10;
	aux_pos.y=aux_pos.y+10;
	disp.setPosition(aux_pos);
	
	
}

esqueletito_::~esqueletito_(){
	
}

bool esqueletito_::le_dispararon(disparo * nalf) {
	// Obtén los límites de los objetos
	sf::FloatRect bounds1 = s_esqueletito.getGlobalBounds();
	sf::FloatRect bounds2 = nalf->getBounds();
	
	// Verifica si se superponen
	if (bounds1.intersects(bounds2)) {
		return true;
	} else {
		return false;
	}
}
vector<particula_explo> esqueletito_::explocion (){
	vector<particula_explo> pe;
	for(int i=0;i<3;i++){
		particula_explo p(139,0,0,s_esqueletito.getPosition());
		pe.push_back(p);
	}
	return pe;
}
void esqueletito_::dibujar (RenderWindow & w) {
	w.draw(s_esqueletito);
	dibujar_barra(w);
	
}
void esqueletito_::actualizar(Vector2f pos_na,Time global) {
	Vector2f pos_enemigo = s_esqueletito.getPosition();
	Vector2f pos_barra = pos_enemigo;
	pos_barra.y -= 40; 
	bar_vida.actualizar(pos_barra);
	if(cambio.getElapsedTime().asMilliseconds()>=200){
		if(flag){
			s_esqueletito.setTexture(t_esq2);
			sonido_disparo.play();
			flag=false;
		}
		else{
			s_esqueletito.setTexture(t_esq1);
			flag=true;
		}
		cambio.restart();
	}
	Vector2f dir=pos_na-s_esqueletito.getPosition();
	float longitud=sqrt((dir.x*dir.x)+(dir.y*dir.y));
	dir/=longitud;
	dir*=velocidad_movimiento;
	s_esqueletito.move(dir);
	disp.move(dir);
}
bool esqueletito_::intersecta(Vector2f pos){
	Vector2f pos_na=pos;
	Vector2f pos_disp=disp.getPosition();
	float dist=sqrt((pos_na.x-pos_disp.x)*(pos_na.x-pos_disp.x)+(pos_na.y-pos_disp.y)*(pos_na.y-pos_disp.y));
	if(dist<30) return true;
	else return false;
}

vector<disparo*> esqueletito_::generardisparo(Vector2f pos_nave){
	vector<disparo*> disparos;
	disparos.push_back(new disparoNave(pos_nave));
	disparos.push_back(new disparoNave(pos_nave));
	return disparos;
}
bool esqueletito_::debedisparar(Time global){
	return false;
}
void esqueletito_::actualizar(){
}

