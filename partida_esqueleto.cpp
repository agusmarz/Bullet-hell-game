#include "partida_esqueleto.h"
#include "esqueleto_.h"
#include <cmath>
#include <iostream>
#include "alien.h"
using namespace std;
partida_esqueleto::partida_esqueleto(){
	Enemigo* ptr_esqueleto=new esqueleto_(200,50,0,0,10);
	ve.push_back(ptr_esqueleto);
}
bool partida_esqueleto::actualizar(){
	na.actualizar();
	if(na.debedisparar()){
		vd_na.push_back(na.generardisparo());
	}
	vector<Enemigo*> ve_temp;
	vector<disparo*> vd_temp;

	for(Enemigo* e:ve){
		if(e->debedisparar()){
			vector<disparo*> aux_disp=e->generardisparo(na.Ver_pos());
			if(aux_disp.size() >= 2) { // Ensure there are at least two elements
				esqueletito_* ptrA = dynamic_cast<esqueletito_*>(aux_disp[0]);
				if(ptrA != nullptr){
					ve_temp.push_back(ptrA);
					esqueletito_* ptrB = dynamic_cast<esqueletito_*>(aux_disp[1]);
					if(ptrB != nullptr){
						ve_temp.push_back(ptrB);
					}
				}
				vd_temp.push_back(aux_disp[0]);
				vd_temp.push_back(aux_disp[1]);
			}
		}
	}
	

	
	// Agregar los elementos del vector temporal al vector original después del bucle
	//para que no se rompa todo jaja
	ve.insert(ve.end(), ve_temp.begin(), ve_temp.end());
	vd.insert(vd.end(), vd_temp.begin(), vd_temp.end());
	ve_temp.erase(ve_temp.begin(),ve_temp.end());
	vd_temp.erase(vd_temp.begin(),vd_temp.end());
	
	for(disparo* d:vd_na){
		d->actualizar();
	}
	for(Enemigo* e:ve){
		e->actualizar(na.Ver_pos());
	}
		
	for(auto it=vd_na.begin();it!=vd_na.end();){
		bool disparoImpactado = false;
		for(auto e = ve.begin(); e != ve.end();){
			if((*e)->le_dispararon(*it)){
				(*e)->perdio_vida();
				disparoImpactado = true;
				if((*e)->ver_vida()==0){
					// Buscar y eliminar el objeto en vd
					disparo* disp = dynamic_cast<disparo*>(*e);
					if (disp != nullptr) {
						auto it2 = find(vd.begin(), vd.end(), disp);
						if (it2 != vd.end()) {
							vd.erase(it2);
						}
					}
					// Eliminar el objeto en ve
					e = ve.erase(e);
					break; 
				}
				else{
					++e;
				}
			}
			else{
				++e;
			}
		}
		if(disparoImpactado){
			it = vd_na.erase(it);
		}
		else{
			++it;
		}
	}
	
	
	for(disparo* d:vd){
		d->actualizar();
		if(d->intersecta(na.Ver_pos())){
			cout<<"perdiste payaso"<<endl;
			return false;
		}
	}
	if(ve.empty()){
	 ptr_esqueleto=new esqueleto_(200,50,0,0,70);
		ve.push_back(ptr_esqueleto);
	}

	
	return true;}
	
void partida_esqueleto:: dibujar(RenderWindow &w){
	fondo.dibujar(w);
	
	
	for(disparo* d:vd){
		d->dibujar(w);
	}
	for(disparo* d:vd_na){
		d->dibujar(w);
	}
	for(Enemigo* d: ve){
		d->dibujar(w);
	}
	na.dibujar(w);
}
