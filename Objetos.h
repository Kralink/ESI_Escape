#ifndef OBJETOS_H
#define OBJETOS_H
 
typedef struct {
    char id [5]; //Identificador del objeto
    char nombre [16]; //Nombre del objeto
    char descripcion [51]; //Descripcion del objeto
    char localizacion [31]; //Localizacion del objeto (Id de la sala o el inventario del jugador)
} Objeto;


#endif 