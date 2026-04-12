#ifndef __CONEXIONES__
#define __CONEXIONES__
#include <string.h>


typedef struct Conexion{
    char id_conexion_[4];
    char id_salaOrigen_[3];
    char nombre_salaOrigen_[30];
    char id_salaDestino_[3];
    char nombre_salaDestino_[30];
    int estado_;                       //Booleano: 0(False)=bloqueada, 1(True)=Abierto
    char id_condicion_[6];             // id_objeto, id_puzle o 0 si no procede.  
}Conexion;

/**
 * @brief Esta funcion imprime el número de conexiones y su listado 
 * @param sala_param Estructura de tipo Sala, que es la sala a describir
 * @return Si es Salida, devuelve 1. Si no, 0.
 */
int puedePasarPorConexion(Conexion conexion);

//Getters
int estaConexionActiva(Conexion conexion);
int estaConexionBloqueada(Conexion conexion);

// Si son iguales, activa la conexión
void desbloquearConexionObjeto(Conexion* conexion_param,const char* id_param );        

void desbloquearConexionPuzle();

void imprimirDebug(const Conexion* conexion_param);           


Conexion* buscarConexionPorId(Conexion *conexiones, int numConexiones, const char *idConexion);
Conexion* buscarConexionEntreSalas(Conexion *conexiones, int numConexiones, const char *idOrigen, const char *idDestino);
int existeConexionEntreSalas(const Conexion *conexiones, int numConexiones, const char *idOrigen, const char *idDestino);
int desbloquearConexionConObjeto(Conexion *conexion, const char *idObjeto);
int desbloquearConexionConPuzle(Conexion *conexion, const char *idPuzle);
void mostrarConexion(const Conexion *conexion);
void mostrarConexionesDesdeSala(const Conexion *conexiones, int numConexiones, const char *idSala);


#endif