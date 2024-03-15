#include "MenuConfig.h"
#include "GLobal.h"
#include <SFML/Window/Keyboard.hpp>
#include "Partida.h"
#include "PMenu.h"

MenuConfig::MenuConfig() {
	buffer_menuclick = *seleccionador_son(11);
	s_menuclick.setBuffer(buffer_menuclick);
	buffer_iniciar = *seleccionador_son(12);
	s_iniciar.setBuffer(buffer_iniciar);
	s_arrow.setTexture(*seleccionador_textur(13));
	s_proletario.setTexture(*seleccionador_textur(7));
	s_alien.setTexture(*seleccionador_textur(0));
	s_esqueleto.setTexture(*seleccionador_textur(12));
	seleccion.setFont(*seleccionador_texto(1));
	seleccion.setString("Selecciona un nivel");
	volver.setFont(*seleccionador_texto(1));
	volver.setString("Presione Escape para volver al menu");
	rectangulito.setSize({100,100});
	rectangulito.setOutlineColor({255,255,255});
	rectangulito.setOutlineThickness(10);
	rectangulito.setFillColor({0,0,0,0});
	rectangulito.setPosition(50,250);
	seleccion.setPosition(250,100);
	volver.setPosition(10,550);
	s_proletario.setScale(0.2,0.2);
	s_proletario.setOrigin(141,180);
	s_alien.setOrigin(431,180);
	s_alien.setColor(Color(255,255,255,50));
	s_esqueleto.setOrigin(378.5,180);
	s_esqueleto.setColor(Color(255,255,255,50));
	s_alien.setScale(0.2,0.2);
	s_esqueleto.setScale(0.2,0.2);
	s_proletario.setPosition(100,300);
	s_alien.setPosition(375,300);
	s_esqueleto.setPosition(650,300);
	time = 200;
	clock.restart();
	
	
}

void MenuConfig::Draw (RenderWindow & w) {
	//w.draw(s_arrow);
	w.draw(s_proletario);
	w.draw(s_alien);
	w.draw(s_esqueleto);
	w.draw(seleccion);
	w.draw(volver);
	w.draw(rectangulito);
}

void MenuConfig::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Escape))game.setScene(new PMenu());
	sleeptime = clock.getElapsedTime().asMilliseconds();
	if(sleeptime>=time){
	if(sleeptime>=time&&(Keyboard::isKeyPressed(Keyboard::Right)&&((rectangulito.getPosition()==Vector2f(50,250))||(rectangulito.getPosition()==Vector2f(270,250))))){
		if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::Right))s_menuclick.play();
		
		clock.restart();
		if(rectangulito.getPosition() == Vector2f(50,250)){
		rectangulito.move(220,0);
		rectangulito.setSize({200,100});
		s_alien.setColor(Color(255,255,255,255));
		s_proletario.setColor(Color(255,255,255,50));
		}else{
			rectangulito.move(285,0);
			rectangulito.setSize({190,100});
			s_esqueleto.setColor(Color(255,255,255,255));
			s_alien.setColor(Color(255,255,255,50));
		}
		
	}
	if(sleeptime>=time&&(Keyboard::isKeyPressed(Keyboard::Left)&&((rectangulito.getPosition()==Vector2f(555,250))||(rectangulito.getPosition()==Vector2f(270,250))))){
		if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::Right))s_menuclick.play();
		
		clock.restart();
		if(rectangulito.getPosition() == Vector2f(555,250)){
			rectangulito.move(-285,0);
			rectangulito.setSize({200,100});
			s_esqueleto.setColor(Color(255,255,255,50));
			s_alien.setColor(Color(255,255,255,255));
		}else{
			rectangulito.move(-220,0);
			rectangulito.setSize({100,100});
			s_alien.setColor(Color(255,255,255,50));
			s_proletario.setColor(Color(255,255,255,255));
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Space)&&(rectangulito.getPosition()==Vector2f(50,250))){
		game.setScene(new Partida(0));
		game.setCurrentPart(0);
	}
	if(Keyboard::isKeyPressed(Keyboard::Space)&&(rectangulito.getPosition()==Vector2f(270,250))){
		game.setScene(new Partida(1));
		game.setCurrentPart(1);
	}	
	if(Keyboard::isKeyPressed(Keyboard::Space)&&(rectangulito.getPosition()==Vector2f(555,250))){
		game.setScene(new Partida(2));
		game.setCurrentPart(2);
	}
	}
	sleeptime = clock.getElapsedTime().asMilliseconds();
}


