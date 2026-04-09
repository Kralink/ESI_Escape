#ifndef REG_SESION_H
#define REG_SESION_H

typedef struct{
    int Id[3];
    char Nombre[21];
    char Clave[9];
} Registro;
//Cabecera: int inicio_sesion(Registro reg[])
//Precondición: Requiere como parámetro la estructura registro
//Postcondición: inicia sesión de un jugador
int inicio_sesion(Registro reg[]); //devuelve un valor dependiendo de si ha iniciado sesion correctamente o no

//Cabecera: void realizar_reg(Registro **reg, int n)
//Precondición: estructura con todos los jugadores dentro del sistema y tamaño de la estructura jugador
//Postcondición: registra los nuevos jugadores, almacenando su nombre, un id que se le otorga automáticamente y una contraseña que el usuario introduzca
void realizar_reg(Registro **reg, int n);

#endif