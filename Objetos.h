#ifndef OBJETOS_H
#define OBJETOS_H
 
typedef struct {
    char id [5]; //Identificador del objeto
    char nombre [16]; //Nombre del objeto
    char descripcion [51]; //Descripcion del objeto
    char localizacion [31]; //Localizacion del objeto (Id de la sala, el inventario del jugador o usado si ya se ha utilizado)
} Objeto;
void borrar_tras_usar(Objeto *objeto);
    //Función que borra el objeto después de usarlo, cambiando su localización a "usado" para indicar que ya no está disponible en el juego.
void usar_objeto(Objeto *objeto);
//Función que permite usar un objeto.
void coger_objeto(Objeto *objeto);
//Función que permite coger un objeto, cambiando su localización al inventario del jugador.
void soltar_objeto(Objeto *objeto);
//Función que permite soltar un objeto, cambiando su localización a la sala donde se encuentra el jugador.
Objeto objetos[10]; //Array de objetos del juego, con un máximo de 10 objetos.
#endif 