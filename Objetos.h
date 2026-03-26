#ifndef OBJETOS_H
#define OBJETOS_H
#define LENGHT 10
typedef struct {
    char id [5]; //Identificador del objeto
    char nombre [16]; //Nombre del objeto
    char descripcion [51]; //Descripcion del objeto
    char localizacion [31]; //Localizacion del objeto (Id de la sala, el inventario del jugador o usado si ya se ha utilizado)
} Objeto;
void cambiar_localizacion(Objeto *obj, char *nueva_localizacion);
//Cambia la localizacion de un objeto a una nueva localizacion (id de sala, inventario o usado).
void examinar_objetos(Objeto *objetos[], int id_sala, int num_objetos);
//Busca que objetos hay en la sala y los muestra por pantalla al "Examninar"
void nombreo_inventario(Objeto *objetos[], int i);
//Filtra los objetos cuya localización sea "Inventario" y los muestra por pantalla.
void descripcion_inventario(Objeto *objetos[], int i);
//Filtra los objetos cuya localización sea "Inventario" y muestra su descripcion por pantalla.
int usar_objeto(Objeto *obj, char *id_requerido);
//Usa el objeto seleccionado y comprueba si sirve para abrir la conexion seleccionada.
#endif 