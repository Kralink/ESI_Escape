#ifndef __SALAS__
#define __SALAS__
#include "Conexiones.h"

typedef struct Sala{
    char id_sala_[3];
    char nombre_[31];
    char tipo_[8];    //INICIAL, NORMAL o SALIDA
    char descripcion_[151];
}Sala;

// typedef struct Conexion{
//     char id_salaOrigen[3];
// };

void cambiarSala(Sala sala_param){} 
void describirPrintSala(Sala sala_param){}
void describirSalidas(Sala sala_param){}



#endif