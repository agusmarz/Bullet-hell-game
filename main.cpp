

#include "Game.h"
#include "GLobal.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	cargarTexturas();
	cargarMusica();
	cargarSonidos();
	carga_texto();
	Game g;
	g.Run();
}


