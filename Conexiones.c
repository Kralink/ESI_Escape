#include <stdio.h>
#include <stdlib.h>
#include "Conexiones.h"

void desbloquearConexion(Conexion* conexion_param, char* id_param ){
    if(!strcmp(conexion_param->id_condicion_,id_param)){         //strcmp devuelve 0 si son iguales
        conexion_param->estado_=1;                               
    }
}

void imprimirDebug(Conexion* conexion_param){
    printf("%s",conexion_param->id_condicion_);
}