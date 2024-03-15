#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "fondo_p.h"
#include "Scene.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
class Scene;
class Game {
public:
	Game();
	void Run();
	void Update();
	void Draw();
	void ProcessEvent();
	void setScene(Scene *next_scene);
	void setPauseScene(Scene *pause_scene);
	void Resume();
	void setCurrentPart(int i);
	void sceneHandler();
	void soundHandler();
	void isPlaying(bool flag);
	bool onNosotros();
	int getCurrentPart();
	Scene* getAuxScene();
	
	
private:
	RenderWindow w;
	Scene *g_scene;
	Scene *aux_scene;
	Scene *m_next_scene = nullptr;
	int currentpart;
	SoundBuffer buffer_iniciar;
	Sound s_iniciar;
	Music* song;
	Clock clock;
	double sleeptime;
	double time;
	bool playing;
	bool music;
};

#endif

