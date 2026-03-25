#include<stdio.h>
#include<stdlib.h>
#include "Puzzles.h"
#include <string.h>
Puzzle* puzzle_sala (Puzzle *puzzles[], char*id_sala, int num_puzzles);
void descripcion (Puzzle *p);



Puzzle* puzzle_sala (Puzzle *puzzles[], char*id_sala,int num_puzzles)
{
    for (int i=0; i<= num_puzzles; i++){
        if (strcmp (puzzles[i]->id_sala, id_sala)==0)  //Devuelve cual es el puzzle de la sala en la que se encuentra el jugador                                
            return &puzzles[i];
    } return NULL;       //Si llega hasta aquí significa que ha recorrido todos los puzzles y ninguno coincide
}




void descripcion (Puzzle *p)
{
    if (p==NULL)
        return;
    printf ("Puzzle: %s",p->nombre);
    printf("\n %s",p->descripcion);
}



int resolver_puzzle(Puzzle *p, char *respuestaUsuario) 
{
    if (p->resuelto == 1) {             // Comprobamos si el puzle ya estaba resuelto 
        printf("Este puzle ya ha sido superado.\n");
        return 1;
    }
    if (strcmp(p->solucion, respuestaUsuario) == 0) {   //Comparamos solucion con la solucion del usuario
        p->resuelto = 1;
        return 1;
    } else{
        printf("Respuesta incorrecta");
        return 0;
    }
}
