 #include "Game.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "PMenu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Pausa.h"
#include "GLobal.h"
#include "MenuConfig.h"
#include "nosotrosmenu.h"
#include "GMenu.h"
#include <SFML/Audio/Music.hpp>
using namespace std;

Game::Game():w(VideoMode(800,600),"3Bit",sf::Style::Titlebar | sf::Style::Close){
	w.setFramerateLimit(60);
	buffer_iniciar = *seleccionador_son(12);
	s_iniciar.setBuffer(buffer_iniciar);
	g_scene = new PMenu();
	time = 200;
	song = seleccionador_musica(0);
	song->setLoop(true);
	sf::Image icon;
	icon.loadFromFile("images/cabeza_esqueleto.png");
	w.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
void Game::ProcessEvent(){
	Event e;
	while(w.pollEvent(e)) {
		if(e.type == Event::Closed)
			w.close();	
	}
}
void Game::Run(){
	while(w.isOpen()) {
		
		ProcessEvent();
		Update();
		w.clear();
		Draw();
		w.display();
		soundHandler();
		sceneHandler();
	
	}
	
}
void Game::Update(){
	g_scene->Update(*this);
}
void Game::Draw(){
	g_scene->Draw(w);
}
void Game::setScene(Scene *next_scene){
	m_next_scene = next_scene;
	isPlaying(false);
	
}
void Game::setPauseScene(Scene *pause_scene){
	aux_scene = g_scene;
	setScene(pause_scene);
}

Scene* Game::getAuxScene(){
	return aux_scene; 
}

void Game::setCurrentPart(int i){
	currentpart = i;
}
int Game::getCurrentPart(){
	return currentpart;
}
void Game::isPlaying(bool flag){
	playing = flag;
}
bool Game::onNosotros(){
	nosotrosmenu* nosotrosmenu_ = dynamic_cast<nosotrosmenu *>(g_scene);
	return (nosotrosmenu_ != nullptr); 
}
void Game::soundHandler(){
	PMenu* menuprincipal = dynamic_cast<PMenu *>(g_scene);
	MenuConfig* menuconfig = dynamic_cast<MenuConfig *>(g_scene);
	nosotrosmenu* nosotrosmenu_ = dynamic_cast<nosotrosmenu *>(g_scene);
	
	if(menuprincipal==nullptr and menuconfig == nullptr and nosotrosmenu_ == nullptr){ song->stop(); music = false;}
	if(menuprincipal!=nullptr && !music){song->play(); music = true;}
	sleeptime = clock.getElapsedTime().asMilliseconds();

	if(Keyboard::isKeyPressed(Keyboard::Space)&&sleeptime>=time&&!playing &&!onNosotros()){s_iniciar.play();clock.restart();}
	
	
}
void Game::sceneHandler(){
	if(m_next_scene){
		Pausa* aux = dynamic_cast<Pausa *>(m_next_scene);
		GMenu* gmenu = dynamic_cast<GMenu *>(m_next_scene);
		// si la siguiente escena es un menu de derrota o victoria entonces paramos la musica
		if(gmenu!=nullptr){
			Partida* par = dynamic_cast<Partida *>(g_scene);
			par->stopMusic();
		}
		/*borramos la escena actual a no ser que la siguiente sea una pausa, como se accede a la pausa solo desde la partida, 
		solo sera pausa si estamos en partida, por lo tanto tambien elminara los otros menus en caso de que estemos en uno de ellos
		*/
		if(aux==nullptr){
			delete g_scene;
		}
		// en el caso de que la siguiente escena sea una pausa, pausamos los relojes y la musica de la partida
		else{
			Partida* aux2 = dynamic_cast<Partida *>(g_scene);
			aux2->pausemusic();
			aux2->pausar();
		}
		Partida* aux3 = dynamic_cast<Partida *>(m_next_scene);
		//si la siguiente escena es una partida, entonces despausamos la musica 
		if(aux3!=nullptr){
			aux3->resumemusic();
			aux3->despausar();
		}
		g_scene = m_next_scene;
		m_next_scene = nullptr;
	}
}
