#include <stdio.h>
#include <stdlib.h>
#include "Salas.h"

void describirSala(Sala sala_param){
    printf("%s\n",sala_param.descripcion_);
}

void describirConexiones(Sala sala_param){
    printf("La sala tiene %d conexiones\n",sala_param.numConexiones_);
    for (int i=0; i<sala_param.numConexiones_;i++){
        printf("Conexion %d: %s\n",i+1,sala_param.conexiones[i].nombre_salaDestino_);
    }
}

int esSalaSalida(Sala sala_param){
    // Si la sala es 
    if(!strcmp(sala_param.tipo_,"SALIDA")){         
        return 1;
    }
    else{
        return 0;
    }
}

int esSalaInicial(Sala sala_param)
{
    // Si la sala es 
    if(!strcmp(sala_param.tipo_,"INICIAL")){         
        return 1;
    }
    else{
        return 0;
    }    
}
