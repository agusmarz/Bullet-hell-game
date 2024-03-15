#ifndef ESCOPETA_H
#define ESCOPETA_H
#include "enemigo.h"
#include "proletario.h"
class Escopeta : public Proletario{
public:

	Escopeta(float pos_x, float pos_y, float m_cadencia, float m_velocidad_movimiento, int m_tiempo_spawn, float m_potencia_disp, int ptos_vida,Time global);
	
	virtual vector<disparo*> generardisparo(Vector2f pos_nave) override;
};
#endif
