#include <stdio.h>
#include <stdlib.h>
#include "Objetos.h"
#include <string.h>

void cambiar_localizacion(Objeto *objetos[], char *nueva_localizacion, char *id_objeto, int num_objetos);
void examinar_objetos(Objeto *objetos[], int id_sala, int num_objetos);
int objeto_valido(char*id_objeto_usado, char*id_objeto_requerido);
void nombre_inventario(Objeto *objetos[], int i);
void descripcion_inventario(Objeto *objetos[], int i);




void cambiar_localizacion(Objeto *objetos[], char *nueva_localizacion, char *id_objeto, int num_objetos)
{
    int indice=0;
    for (int i=0; i <= num_objetos; i++){
        if (strcmp (objetos[i]->id,id_objeto)==0){ //si el id coincide con el que buscamos, salimos del bucle.
            break;
            indice=i;
        }
    }
    strcpy(objetos[indice]->localizacion,nueva_localizacion);
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
        printf("%s \n",objetos[i]->nombre);
}


void descripcion_inventario(Objeto *objetos[], int i)
{
  if (strcmp(objetos[i]->localizacion,"inventario")==0) //Si el objeto está en el inventario, imprimimos su descripcion
        printf("%s \n",objetos[i]->descripcion);
}


int objeto_valido(char*id_objeto_usado, char*id_objeto_requerido)
{
    int valido=0;
    if (strcmp(id_objeto_usado,id_objeto_requerido)==0){  //Si el id del objeto coincide 
        valido =1;
        return valido;
    }else
        return valido;
}