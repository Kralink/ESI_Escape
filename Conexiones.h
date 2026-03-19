#ifndef __CONEXIONES__
#define __CONEXIONES__
#include <string.h>

typedef struct Conexion{
    char id_conexion_[4];
    char id_salaOrigen_[3];
    char id_salaDestino_[3];
    int estado_;                       //Booleano: 0(False)=bloqueada, 1(True)=activo
    char id_condicion_[6];             // id_objeto, id_puzle o 0 si no procede.  
    
}Conexion;

// Si son iguales, activa la conexión
void desbloquearConexion(Conexion* conexion_param, char* id_param );

void imprimirDebug(Conexion* conexion_param);



#endif