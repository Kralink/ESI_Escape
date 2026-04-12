#include "Conexiones.h"
#include <stdlib.h>
#include <stdio.h>

int estaConexionActiva(Conexion conexion){
    return conexion.estado_;
}

int puedePasarPorConexion(Conexion conexion){
    
}

void desbloquearConexionObjeto(Conexion conexion_param,char *id_param){
    if(!strcmp(conexion_param.id_condicion_,id_param)){         //strcmp devuelve 0 si son iguales
        conexion_param.estado_=1;                               
    }
}

void desbloquearConexionPuzle(){}

void imprimirDebug(const Conexion* conexion_param){