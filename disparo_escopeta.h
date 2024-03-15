#ifndef DISPARO_ESCOPETA_H
#define DISPARO_ESCOPETA_H
#include "disparo.h"
using namespace std;
using namespace sf;
class disparo_escopeta:public disparo{
public:
	disparo_escopeta(Vector2f pos,Vector2f dir, float potencia_disp);
	virtual void actualizar() override;
	virtual bool intersecta(Vector2f pos)override;
private:
	Vector2f vel_disp;
};
#endif
