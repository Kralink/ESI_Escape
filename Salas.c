#include <stdio.h>
#include <stdlib.h>
#include "Salas.h"

#define LONGITUD_VECTOR_CONEXIONES

void describirPrintSala(Sala sala_param){
    printf("%s\n",sala_param.descripcion_);
}

void describirSalidas(Sala sala_param, Conexion* conexionesVec_param){
    for (int i=0; i<LONGITUD_VECTOR_CONEXIONES;i++){
        if (conexionesVec_param[i].id_salaOrigen_  ==  sala_param.id_sala_)
        {
            printf("%s\n",conexionesVec_param[i].nombre_salaDestino);
        }
        
    }
}