#ifndef DISPARONAVE_H
#define DISPARONAVE_H
#include "disparo.h"

class disparoNave : public disparo {
public:
	disparoNave(Vector2f pos);
	void actualizar();
	virtual bool intersecta(Vector2f pos)override;
private:
};

#endif

