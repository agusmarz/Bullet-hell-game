#ifndef ESQUELETITO__H
#define ESQUELETITO__H
#include "enemigo.h"
#include "disparo.h"
#include "particula_explo.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class esqueletito_ : public Enemigo, public disparo {
public:
	esqueletito_(float width, float height,float startX, float startY, int ptos_vida,Vector2f pos, float m_velocidad);
	~esqueletito_();
	virtual bool le_dispararon (disparo * nalf)override ;
	virtual void dibujar (RenderWindow & w)override ;
	virtual void actualizar()override;
	virtual void actualizar (Vector2f pos_na,Time global)override ;
	virtual vector<disparo*> generardisparo(Vector2f pos_nave) override ;
	virtual bool debedisparar(Time global) override ;
	Vector2f ver_pos();
	virtual bool intersecta(Vector2f pos)override;
	virtual vector<particula_explo> explocion() override;
	private:
	Clock cambio;
	Sprite s_esqueletito;
	bool flag;
};

#endif

