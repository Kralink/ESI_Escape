#ifndef __SALAS__
#define __SALAS__

typedef struct Sala{
    char id_sala_[3];
    char nombre_[31];
    char tipo_[8];    //INICIAL, NORMAL o SALIDA
    char descripcion_[151];
    
}Sala;

void rellenarSalas(fichero);




#endif