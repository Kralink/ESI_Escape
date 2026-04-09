#ifndef GESTIONFICHERO_H
#define GESTIONFICHERO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Objetos.h"
#include "Puzzles.h"
#include "Reg_sesion.h"
#include "Conexiones.h"
#include "Salas.h"

/*
=============================
     FUNCIONES DE CARGA
=============================
*/
void cargar_salas(const char *archivo, Sala **salas, int *num_salas);

void cargar_conexiones(const char *archivo, Conexion **conexiones, int *num_conexiones);

void cargar_objetos(const char *archivo, Objeto **objetos, int *num_objetos);

void cargar_puzles(const char *archivo, Puzzle **puzles, int *num_puzles);

void cargar_registro(const char *archivo, Registro **r);

void cargar_jugador(const char *archivo, Jugador **jugador);

/*
=============================
   FUNCIONES DE GUARDADO
=============================
*/

void guardar_salas(const char *archivo, const Sala *salas, int num_salas);

void guardar_conexiones(const char *archivo, const Conexion *conexiones, int num_conexiones);

void guardar_objetos(const char *archivo, const Objeto *objetos, int num_objetos);

void guardar_puzles(const char *archivo, const Puzzle *puzles, int num_puzles);

void guardar_registro(const char *archivo, const Registro *r);

void guardar_jugador(const char *archivo, const Jugador *jugador);

#endif //GESTIONFICHERO_H
