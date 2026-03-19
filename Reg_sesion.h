#ifndef REG_SESION_H
#define REG_SESION_H

typedef struct{
    int Id[3];
    char Nombre[21];
    char Clave[9];
} Registro;

int inicio_sesion(Registro reg[]); //devuelve un valor dependiendo de si ha iniciado sesion correctamente o no
void realizar_reg(Registro reg[]); //registra a un nuevo usuario almacenando

#endif