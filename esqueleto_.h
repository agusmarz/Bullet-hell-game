#ifndef ESQUELETO__H
#define ESQUELETO__H
#include "enemigo.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "esqueletito_.h"
#include "particula_explo.h"

class esqueleto_ : public Enemigo {
public:
	esqueleto_(int cadencia,int tiempo_spawn,float potencia_disp, int ptos_vida,Time global);
	~esqueleto_();
	bool le_dispararon (disparo * nalf);
	void dibujar (RenderWindow & w);
	void actualizar (Vector2f pos_na,Time global);
	virtual vector<disparo*> generardisparo (Vector2f pos_nave) override;
	pair<esqueletito_*,esqueletito_*> generarEqueletito (Vector2f pos_nave);
	bool debedisparar (Time global);
	void restart_clock(Time global);
	virtual vector<particula_explo> explocion() override;
	virtual void detener_sonido() override;
private:
	Vector2f velocidad;
	int vida_max;
	double angle_movimiento;
	CircleShape outerCircle1;
	CircleShape outerCircle2;
	Sprite s_mano_izq,s_mano_der,s_cabeza;
	int c_cambio;
	bool b_cambio;
	CircleShape centro_izq;
	CircleShape centro_der;
	SoundBuffer buffer_disparo2;
	Sound sonido_disparo2;
};

#endif

