#include "Global.h"
using namespace sf;
Texture t_alien, t_turbina,t_8bit,t_youlose,t_3bit,t_youwin, t_flechita, t_nosotros,t_esq1, t_esq2, t_nave_frente, t_nave_izquierda, t_nave_derecha, t_esclavo_frente, t_esclavo_izq, t_esclavo_der,t_mano_der_esq,t_mano_izq_esq, t_cabeza_esq;
void cargarTexturas(){
	t_esclavo_frente.loadFromFile("images/nave_raptor.png");
	t_esclavo_der.loadFromFile("images/nave_raptor_der.png");
	t_esclavo_izq.loadFromFile("images/nave_raptor_izq.png");
	t_alien.loadFromFile("images/alien.png");
	t_turbina.loadFromFile("images/turbina alien.png"); 
	t_esq1.loadFromFile("images/esqueletito 1.png");
	t_esq2.loadFromFile("images/esqueletito 2.png");
	t_nave_frente.loadFromFile("images/nave_frente.png");
	t_nave_izquierda.loadFromFile("images/nave_izquierda.png");
	t_nave_derecha.loadFromFile("images/nave_derecha.png");
	t_mano_der_esq.loadFromFile("images/mano_derecha_esqueleto.png");
	t_mano_izq_esq.loadFromFile("images/mano_izquierda_esqueleto.png");
	t_cabeza_esq.loadFromFile("images/cabeza_esqueleto.png");
	t_flechita.loadFromFile("images/arrow.png"); 
	t_youwin.loadFromFile("images/youwin.png");
	t_youlose.loadFromFile("images/youlose.png");
	t_3bit.loadFromFile("images/3bits.png");
	t_nosotros.loadFromFile("images/nosotros.jpg");
	
}
Font  fuente;
void carga_texto(){
	fuente.loadFromFile("fuente.ttf");
}
Font* seleccionador_texto(int i){
	Font *aux;
	switch(i){
	case 1: aux=&fuente;break;
	}
	return aux;
}


Texture* seleccionador_textur(int i){
		Texture *aux;
		switch(i){
		case 0:	aux=&t_alien; break; 
		case 1: aux=&t_turbina; break; 
		case 2: aux=&t_esq1; break; 
		case 3: aux=&t_esq2; break;
		case 4: aux=&t_nave_frente; break;
		case 5:	aux=&t_nave_izquierda; break;
		case 6:	aux=&t_nave_derecha; break;
		case 7: aux=&t_esclavo_frente;break;
		case 8:	aux=&t_esclavo_izq;break;
		case 9:	aux=&t_esclavo_der;break;
		case 10: aux=&t_mano_der_esq;break;
		case 11: aux=&t_mano_izq_esq;break;
		case 12: aux=&t_cabeza_esq;break;
		case 13: aux=&t_flechita;break;
		case 14: aux=&t_youwin;break;
		case 15: aux=&t_youlose;break;
		case 16: aux=&t_3bit;break;
		case 17: aux=&t_nosotros;break;
		}
		return aux;
		
	}

		SoundBuffer son_nave,son_alien, perdiste,ganaste, menuclick, iniciar, son_esqueleto_disp1, son_esqueleto_disp2, son_raptor, son_escopeta, son_mcqueen,  son_mcqueen_fin, son_esqueletito;
		
		void cargarSonidos(){
			son_alien.loadFromFile("sonido/disparos/alien.wav");
			son_esqueleto_disp1.loadFromFile("sonido/disparos/esqueleto_disp1.wav");
			son_esqueleto_disp2.loadFromFile("sonido/disparos/esqueleto_disp2.wav");
			son_raptor.loadFromFile("sonido/disparos/raptor.wav");
			son_escopeta.loadFromFile("sonido/disparos/escopeta.wav");
			son_mcqueen.loadFromFile("sonido/disparos/mcqueen.wav");
			son_nave.loadFromFile("sonido/disparos/nave.wav");
			son_mcqueen_fin.loadFromFile("sonido/disparos/mcqueen-fin.wav");
			son_esqueletito.loadFromFile("sonido/disparos/esqueletito.wav");
			menuclick.loadFromFile("sonido/menu/menuclick.wav");
			iniciar.loadFromFile("sonido/menu/iniciar.wav");
			perdiste.loadFromFile("sonido/menu/perdiste.wav");
			ganaste.loadFromFile("sonido/menu/ganaste.wav");
		}
			
			SoundBuffer* seleccionador_son(int i){
				SoundBuffer *aux;
				switch(i)
				{
				case 0:	aux=&son_alien; break; 
				case 1: aux=&son_esqueleto_disp1; break; 
				case 2: aux=&son_raptor; break; 
				case 3: aux=&son_escopeta; break;
				case 4: aux=&son_mcqueen; break;
				case 7: aux=&son_nave; break;
				case 8: aux=&son_mcqueen_fin; break;
				case 9: aux=&son_esqueletito; break;
				case 10: aux=&son_esqueleto_disp2; break; 
				case 11: aux=&menuclick;break;
				case 12: aux=&iniciar;break;
				case 13: aux=&perdiste;break;
				case 14: aux=&ganaste;break;
				}
				return aux;
			}
				
string seleccionador_nivel(int i){
	string nombre;
	switch(i){
	case 0:nombre="datos_enemigos.txt";break;
	case 1:nombre="datos_enemigos2.txt";break;
	case 2:nombre="datos_enemigos3.txt";break;
	}
	return nombre;
}
Music cancion1, cancion2,cancion3,cancion4;
void cargarMusica(){
	cancion1.openFromFile("sonido/canciones/song.wav");
	cancion2.openFromFile("sonido/canciones/4estaciones.wav");
	cancion3.openFromFile("sonido/canciones/5tasinfonia.wav");
	cancion4.openFromFile("sonido/canciones/Lacrimosa.wav");
}
Music* seleccionador_musica(int i){
	Music* cancion;
	switch(i){
	case 0: cancion=&cancion1;break;
	case 1: cancion=&cancion2;break;
	case 2: cancion=&cancion3;break;
	case 3: cancion=&cancion4;break;
	}
	return cancion;
}
