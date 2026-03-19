#ifndef OBJETOS_H
#define OBJETOS_H
#define LENGHT 10
typedef struct {
    char id [5]; //Identificador del objeto
    char nombre [16]; //Nombre del objeto
    char descripcion [51]; //Descripcion del objeto
    char localizacion [31]; //Localizacion del objeto (Id de la sala, el inventario del jugador o usado si ya se ha utilizado)
} Objeto;
void cambiar_localizacion(Objeto *objetos[], char *nueva_localizacion, char *id_objeto, int num_objetos);
//Cambia la localizacion de un objeto a una nueva localizacion (id de sala, inventario o usado).
void examinar_objetos(Objeto *objetos[], int id_sala, int num_objetos);
//Busca que objetos hay en la sala y los muestra por pantalla al "Examninar"
int objeto_valido(char*id_objeto_usado, char*id_objeto_requerido);
//Comprueba al "usar objeto" que el objeto que se quiere usar coincide con el que el puzzle espera.
void nombreo_inventario(Objeto *objetos[], int i);
//Filtra los objetos cuya localización sea "Inventario" y los muestra por pantalla.
void descripcion_inventario(Objeto *objetos[], int i);
//Filtra los objetos cuya localización sea "Inventario" y muestra su descripcion por pantalla.

#endif 