#ifndef LIBRERIAS_H
#define LIBRERIAS_H
#include <string>
using namespace std;
void compresion_y_descompresion_rle();
void compresion_y_descompresion_lz78();
void encriptacion_desencriptacion(char textos[]);
string leer_archivo(char c[]);
void guardar_en_archivo(string contenido);
void cambiar_a_char(string texto, char tex[]);
#endif // LIBRERIAS_H
