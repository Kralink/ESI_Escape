#ifndef REG_SESION_H
#define REG_SESION_H

typedef struct{
    int Id[3];
    char Nombre[21];
    char Clave[9];
} Registro;

int inicio_sesion(Registro reg[]); //devuelve un valor dependiendo de si ha iniciado sesion correctamente o no

//Esta función registra los nuevos jugadores, almacenando su nombre, un id que se le otorga automáticamente y una contraseña que el usuario introduzca
//Verifica primero antes de almacenar un jugador si el nombre que se introduce ya existe
//Parámetros: estructura con todos los jugadores dentro del sistema y tamaño de la estructura
void realizar_reg(Registro **reg, int n);

#endif