#ifndef DISPARO_MCQUEEN_H
#define DISPARO_MCQUEEN_H
#include "disparo.h"
using namespace std;
using namespace sf;
class disparo_mcqueen : public disparo{
public:
	disparo_mcqueen(Vector2f pos,Vector2f dir, float potencia_disp);
	void actualizar() override;
	virtual bool intersecta(Vector2f pos)override;
private:
	Vector2f vel_disp;
};
#endif
