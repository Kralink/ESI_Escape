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

/*
@brief Comprueba si puede pasar por la conexión 
@param const Conexion *conexion
*/
int puedePasarPorConexion(const Conexion *conexion);

// Si son iguales, activa la conexión
void desbloquearConexionObjeto(Conexion* conexion_param,const char* id_param );        

void desbloquearConexionPuzle();

void imprimirDebug(const Conexion* conexion_param);           

int estaConexionActiva(const Conexion *conexion);
int estaConexionBloqueada(const Conexion *conexion);
Conexion* buscarConexionPorId(Conexion *conexiones, int numConexiones, const char *idConexion);
Conexion* buscarConexionEntreSalas(Conexion *conexiones, int numConexiones, const char *idOrigen, const char *idDestino);
int existeConexionEntreSalas(const Conexion *conexiones, int numConexiones, const char *idOrigen, const char *idDestino);
int desbloquearConexionConObjeto(Conexion *conexion, const char *idObjeto);
int desbloquearConexionConPuzle(Conexion *conexion, const char *idPuzle);
void mostrarConexion(const Conexion *conexion);
void mostrarConexionesDesdeSala(const Conexion *conexiones, int numConexiones, const char *idSala);


#endif