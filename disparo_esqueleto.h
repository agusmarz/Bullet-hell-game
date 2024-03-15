#ifndef DISPARO_ESQUELETO_H
#define DISPARO_ESQUELETO_H
#include "disparo.h"
#include <SFML/System/Vector2.hpp>
using namespace sf;
class disparo_esqueleto : public disparo {
public:
	disparo_esqueleto(Vector2f pos);
	void actualizar ();
	virtual bool intersecta(Vector2f pos)override;
private:
};

#endif

