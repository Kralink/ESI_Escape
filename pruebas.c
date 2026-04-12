#include "Conexiones.h"
#include "Salas.h"
#include <stdio.h>

int main(void){
    Conexion conexiones[2];

    strcpy(conexiones[0].id_conexion_, "C1");
    strcpy(conexiones[0].id_salaOrigen_, "A1");
    strcpy(conexiones[0].nombre_salaOrigen_, "Entrada");
    strcpy(conexiones[0].id_salaDestino_, "B1");
    strcpy(conexiones[0].nombre_salaDestino_, "Pasillo");
    conexiones[0].estado_ = 1;
    strcpy(conexiones[0].id_condicion_, "0");

    strcpy(conexiones[1].id_conexion_, "C2");
    strcpy(conexiones[1].id_salaOrigen_, "A1");
    strcpy(conexiones[1].nombre_salaOrigen_, "Entrada");
    strcpy(conexiones[1].id_salaDestino_, "C1");
    strcpy(conexiones[1].nombre_salaDestino_, "Cocina");
    conexiones[1].estado_ = 0;
    strcpy(conexiones[1].id_condicion_, "OBJ1");

    Sala sala;

    strcpy(sala.id_sala_, "A1");
    strcpy(sala.nombre_, "Entrada");
    strcpy(sala.tipo_, "INICIAL");
    strcpy(sala.descripcion_, "Sala inicial del juego");
    sala.numConexiones_ = 2;
    sala.conexiones = conexiones;

    describirConexiones(sala);

    return 0;
}