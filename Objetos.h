#ifndef OBJETOS_H
#define OBJETOS_H
#define LENGHT 10
typedef struct {
    char id [5]; //Identificador del objeto
    char nombre [16]; //Nombre del objeto
    char descripcion [51]; //Descripcion del objeto
    char localizacion [31]; //Localizacion del objeto (Id de la sala, el inventario del jugador o usado si ya se ha utilizado)
} Objeto;
//Cabecera: void cambiar_localizacion(Objeto *obj, char *nueva_localizacion);
//Precondición: Recibe un objeto y la nueva localizacion. 
//Postcondición: Cambia la localizacion del objeto, ya sea al soltarlo, al cogerlo o al usarlo
void cambiar_localizacion(Objeto *obj, char *nueva_localizacion);
//Cabecera: void examinar_objetos(Objeto *objetos[], int id_sala, int num_objetos);
//Precondición: Recibe la sala en la que se encuentra el jugador
//Postcondición: Muestra los objetos que hay en la sala donde se encuentra el jugador
void examinar_objetos(Objeto *objetos[], int id_sala, int num_objetos);
//Cabecera: void nombre_inventario(Objeto *objetos[], int i);
//Precondición: Recibe el vector de objetos 
//Postcondición: Muestra por pantalla los objetos que están en el inventario
void nombre_inventario(Objeto *objetos[], int i);
//Cabecera: int usar_objeto(Objeto *obj, char *id_requerido);
//Precondición: Recibe un objeto y el id del objeto que hace falta 
//Postcondición: Devuelve 1 si el objeto es el adecuado o 0 sino lo es 
int usar_objeto(Objeto *obj, char *id_requerido);
#endif 