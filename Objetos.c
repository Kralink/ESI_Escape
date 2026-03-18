#include <stdio.h>
#include <stdlib.h>
#include "Objetos.h"

int main()
{ 
    FILE *f;
    f = fopen("Objetos.txt", "w+");
    if (f == NULL) //Comprobamos que el archivo se ha abierto correctamente
    {
        printf("Error al abrir el archivo");
        return 1;
    }
    
    fclose(f);

    return 0;
}