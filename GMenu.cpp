#include "GMenu.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "fondo_p.h"
#include <iostream>
#include "PMenu.h"
#include "GLobal.h"
using namespace std;
using namespace sf;
GMenu::GMenu(bool _estado) {
	
	reiniciar.setFont(*seleccionador_texto(1));
	reiniciar.setPosition(450,500);
	reiniciar.setFillColor(Color(255,255,255,100));
	reiniciar.setString("Reiniciar");
	menu.setFont(*seleccionador_texto(1));
	menu.setPosition(200, 500);
	menu.setFillColor(Color(255,255,255,255));
	menu.setString("Vover al menu");
	
	s_arrow.setTexture(*seleccionador_textur(13));
	s_arrow.setPosition(300,600);
	s_arrow.rotate(-90);
	s_arrow.setScale(0.5,0.5);
	estado = _estado;
	buffer_menuclick = *seleccionador_son(11);
	s_menuclick.setBuffer(buffer_menuclick);
	buffer_iniciar = *seleccionador_son(12);
	s_iniciar.setBuffer(buffer_iniciar);
	buffer_perdiste = *seleccionador_son(13);
	s_perdiste.setBuffer(buffer_perdiste);
	buffer_ganaste= *seleccionador_son(14);
	s_ganaste.setBuffer(buffer_ganaste);
	if(!_estado) s_perdiste.play();
	if(_estado)s_ganaste.play();
	
}
void GMenu::Draw(RenderWindow &w){
	
	if(estado){
		s_youwin.setTexture(*seleccionador_textur(14));
		s_youwin.scale(0.01,0.01);
		s_youwin.setColor(Color(0,255,0,255));
		s_youwin.setOrigin(512,512);
		s_youwin.setPosition(400,250);
		elec = s_youwin;
		
		
	}else{
		s_youlose.setTexture(*seleccionador_textur(15));
		s_youlose.scale(0.01,0.01);
		s_youlose.setOrigin(512,512);
		s_youlose.setPosition(400,300);
		elec = s_youlose;
	}
	s_3bits.setTexture(*seleccionador_textur(16));
	s_3bits.scale(0.15,0.15);
	s_3bits.setPosition(10,10);
	
	if(estado)elec.setColor(Color(rand()%255,rand()%255,rand()%255,255));
	if(escalas.x<0.45){
		escalas.x += 0.03;
		escalas.y += 0.03;
		elec.setScale(escalas);
	}else{
		elec.setScale(escalas);
	}
	w.draw(elec);
	w.draw(s_3bits);
	w.draw(menu);
	w.draw(reiniciar);
	w.draw(s_arrow);
	fondo.dibujar(w);
}
void GMenu::Update(Game &game){
	
	if(Keyboard::isKeyPressed(Keyboard::Right)&& (s_arrow.getPosition()!= Vector2f(450,600))){
		s_menuclick.play();
		s_arrow.move(150,0);
		menu.setFillColor(Color(255,255,255,100));
		reiniciar.setFillColor(Color(255,255,255,255));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)&& (s_arrow.getPosition()!= Vector2f(300,600))){
		s_menuclick.play();
		s_arrow.move(-150,0);
		menu.setFillColor(Color(255,255,255,255));
		reiniciar.setFillColor(Color(255,255,255,100));
	}
		//reiniciar
	if(Keyboard::isKeyPressed(Keyboard::Space)&&(s_arrow.getPosition()==Vector2f(450,600))){
		s_iniciar.play();
		game.setScene(new Partida(game.getCurrentPart()));
		
	}
		//ir al menu
	if(Keyboard::isKeyPressed(Keyboard::Space)&&(s_arrow.getPosition()==Vector2f(300,600))){
		s_iniciar.play();
		game.setScene(new PMenu());
	}
	
	
}


