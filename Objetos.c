#include <stdio.h>
#include <stdlib.h>
#include "Objetos.h"
#include <string.h>

void cambiar_localizacion(Objeto *obj, char *nueva_localizacion);
void examinar_objetos(Objeto *objetos[], int id_sala, int num_objetos);
void nombre_inventario(Objeto *objetos[], int i);
void descripcion_inventario(Objeto *objetos[], int i);
int usar_objeto(Objeto *obj, char *id_requerido);



void cambiar_localizacion(Objeto *obj, char *nueva_localizacion)
{
    strcpy(obj->localizacion,nueva_localizacion);
}


void examinar_objetos(Objeto*objetos[], int id_sala, int num_objetos)
{
    for (int i=0; i<=num_objetos;i++)
    {
        if (strcmp(objetos[i]->localizacion,id_sala)==0)  //Si el objeto está en la sala, imprimimos su nombre.
            printf("%s",objetos[i]->nombre);
    }
}


void nombre_inventario(Objeto *objetos[], int i)
{
     if (strcmp(objetos[i]->localizacion,"inventario")==0) //Si el objeto está en el inventario, imprimimos su nombre
        printf("%s: %s \n",objetos[i]->nombre, objetos[i]->descripcion);
       
}


int usar_objeto(Objeto *obj, char *id_requerido)
{
    if (strcmp(obj->id,id_requerido)==0){
        prinntf("CONEXION DESBLOQUEADA");
        cambiar_localizacion(obj,"usado");
        return 1;
    }else
        printf("Este objeto no sirve para desbloquear esta conexion");
        return 0;
}
