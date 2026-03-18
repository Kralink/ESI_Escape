#include <stdio.h>
#include <stdlib.h>
#include "Objetos.h"
#include <string.h>
void borrar_tras_usar(Objeto *objeto);
void usar_objeto(Objeto *objeto);
void coger_objeto(Objeto *objeto);
void soltar_objeto(Objeto *objeto);
int main()
{ 
    return 0;
}

void coger_objeto  (Objeto *objeto)
{
    strcpy(objeto->localizacion, "inventario");
    //Hay que borrar el objeto de la sala.
}



void soltar_objeto (Objeto *objeto)
{
    strcpy(objeto->localizacion, "//id de la sala donde se encuentra el jugador");
    //Hay que borrar el objeto del inventario.
    //Hay que añadir el objeto a la sala.
}

