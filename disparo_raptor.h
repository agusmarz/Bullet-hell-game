#ifndef DISPARO_RAPTOR_H
#define DISPARO_RAPTOR_H
#include "disparo.h"
using namespace std;
using namespace sf;
class disparo_raptor : public disparo{
public:
	disparo_raptor(Vector2f pos,Vector2f dir, float potencia_disp);
	void actualizar() override;
	bool intersecta(Vector2f pos) override;
private:
	Vector2f vel_disp;
};
#endif
