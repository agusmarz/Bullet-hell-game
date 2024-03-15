#ifndef GLOBAL_H
#define GLOBAL_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>
using namespace std;
using namespace sf;
void cargarTexturas();
Texture* seleccionador_textur(int i);
extern Texture t_alien, t_turbina, t_esq1, t_esq2, t_nave_frente, t_nave_izquierda, t_nave_derecha, t_esclavo_frente, t_esclavo_izq, t_esclavo_der,
	t_mano_der_esq,t_mano_izq_esq, t_cabeza_esq,t_3bit,t_youlose,t_youwin, t_flechita, t_nosotros;
void cargarSonidos();
SoundBuffer* seleccionador_son(int i);
extern SoundBuffer son_nave,son_alien,menuclick, perdiste, ganaste, iniciar, son_esqueleto_disp1,son_esqueleto_disp2, son_raptor, son_escopeta, son_mcqueen,  son_mcqueen_fin, son_esqueletito;
void carga_texto();
Font* seleccionador_texto(int i);
extern Font fuente;
string seleccionador_nivel(int i);
Music* seleccionador_musica(int i);
extern Music cancion1,cancion2,cancion3,cancion4;
void cargarMusica();
#endif
