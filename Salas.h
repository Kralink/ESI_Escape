#ifndef __SALAS__
#define __SALAS__
#include "Conexiones.h"

typedef struct Sala{
    char id_sala_[3];
    char nombre_[31];
    char tipo_[8];    //INICIAL, NORMAL o SALIDA
    char descripcion_[151];
    int numConexiones_;
    Conexion* conexiones;
}Sala;

/**
 * @brief Esta funcion describe la sala
 * @param sala_param Estructura de tipo Sala, que es la sala a describir
 */
void describirSala(Sala sala_param);

/**
 * @brief Esta funcion imprime el número de conexiones y su listado 
 * @param sala_param Estructura de tipo Sala, que es la sala a describir
 */
void describirConexiones(Sala sala_param);

/**
 * @brief Esta funcion imprime el número de conexiones y su listado 
 * @param sala_param Estructura de tipo Sala, que es la sala a describir
 * @return Si es Salida, devuelve 1. Si no, 0.
 */
int esSalaSalida(Sala sala_param);

/**
 * @brief Esta funcion imprime el número de conexiones y su listado 
 * @param sala_param Estructura de tipo Sala, que es la sala a describir
 * @return Si es Salida, devuelve 1. Si no, 0.
 */
int esSalaInicial(Sala sala_param);

void cambiarSala(Sala sala_param); 


#endif