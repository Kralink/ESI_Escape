#ifndef __SALAS__
#define __SALAS__
#include "Conexiones.h"

typedef struct Sala{
    char id_sala_[3];
    char nombre_[31];
    char tipo_[8];    //INICIAL, NORMAL o SALIDA
    char descripcion_[151];
    int numConexiones_;
}Sala;



/*
@brief Esta funcion describe la sala
@param struct Sala sala_param: 
@return lo que devuelve
*/
void describirSala(const Sala *sala_param);


void cambiarSala(Sala sala_param); 

void describirConexiones(Sala sala_param, Conexion* conexionesVec_param, int numConexiones);


int esSalaSalida(const Sala *sala);

int esSalaInicial(const Sala *sala);


#endif