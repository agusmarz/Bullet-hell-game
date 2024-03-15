#include "nosotrosmenu.h"
#include "GLobal.h"
#include <SFML/Window/Keyboard.hpp>
#include "PMenu.h"

nosotrosmenu::nosotrosmenu() {
	foto.setTexture(*seleccionador_textur(17));
	foto.setScale(0.4,0.4);
	foto.setOrigin(540,540);
	foto.setPosition(400,220);
	textito.setFont(*seleccionador_texto(1));
	textito2.setFont(*seleccionador_texto(1));
	textito.setString("El de rojo es Fausto \nEl de verde es Agus \nEl de azul es Nacho \nNada mas que agregar por ahora");
	textito2.setString("Esc para volver");
	textito2.setPosition(0,0);
	textito.setPosition(50,450);
}

void nosotrosmenu::Draw (RenderWindow & w) {
	w.draw(foto);
	w.draw(textito);
}

void nosotrosmenu::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Escape))game.setScene(new PMenu());
}

