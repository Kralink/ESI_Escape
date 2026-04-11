#include <stdio.h>
#include <stdlib.h>
#include "Salas.h"



void describirSala(const Sala *sala_param){
    printf("%s\n",sala_param->descripcion_);
}


void describirConexiones(Sala sala_param, Conexion* conexionesVec_param, int numConexiones){
    for (int i=0; i<numConexiones;i++){
        if (conexionesVec_param[i].id_salaOrigen_  ==  sala_param.id_sala_){
            printf("%s\n",conexionesVec_param[i].nombre_salaDestino);
        }
    }
}