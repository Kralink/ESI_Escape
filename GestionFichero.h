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
void cargar_salas();

void cargar_conexiones();

void cargar_objetos();

void cargar_puzles();

void cargar_registro();



/*
=============================
   FUNCIONES DE GUARDADO
=============================
*/

void guardar_salas();

void guardar_conexiones();

void guardar_objetos();

void guardar_puzles(); 

void guardar_registro();

#endif //GESTIONFICHERO_H