#ifndef PARTIDA_ESQUELETO_H
#define PARTIDA_ESQUELETO_H
#include "enemigo.h"
#include "fondo_p.h"
#include "nave.h"
#include <vector>
#include "disparo.h"
#include "esqueleto_.h"
using namespace std;
using namespace sf;
class partida_esqueleto {
public:
	partida_esqueleto();
	void dibujar(RenderWindow &w);
	bool actualizar();
private:
	Enemigo *ptr_esqueleto;
	fondo_p fondo;
	nave na;
	vector<Enemigo*> ve;
	vector<disparo*> vd_na;
	vector<disparo*> vd;
};

#endif

