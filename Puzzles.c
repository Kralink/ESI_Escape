#include<stdio.h>
#include<stdlib.h>
#include "Puzzles.h"
#include <string.h>
Puzzle* puzzle_sala (Puzzle *puzzles[], char*id_sala, int num_puzzles);
void descripcion (Puzzle *p);
int resolver_puzzle(Puzzle *p);


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
    printf ("Puzzle: %s",p->nombre);  //Muestra tanto el nombre como la descripcion del puzzle-
    printf("\n %s",p->descripcion);
}



int resolver_puzzle(Puzzle *p) 
{
    char *respuesta_usuario[10];
    if (p==NULL){
        printf("En esta sala no hay puzzle que resolver");
        return;
    }
    if (p->resuelto == 1) {             // Comprobamos si el puzle ya estaba resuelto 
        printf("Este puzle ya ha sido superado.\n");
        return 1;
    }
    
    for (int i=3; i>=0;i--){
        printf("Introduzca la solución del puzzle: ");
        scanf ("%s",&respuesta_usuario);
        if (strcmp(p->solucion, respuesta_usuario) == 0) {   //Comparamos solucion del puzzle con la del usuario
            p->resuelto = 1;
            printf("RESPUESTA CORRECTA");
            return 1;
        } else{
            printf("Respuesta incorrecta, te quedan %i intentos.",i);
            return 0;
        }
    }
}
