#include<stdio.h>
#include<stdlib.h>
#include "Puzzles.h"
#include <string.h>
int puzzle_sala (Puzzle *puzzles[], char*id_sala, int num_puzzles);
void resuelto (char* id,Puzzle *puzzles[]);




int puzzle_sala (Puzzle *puzzles[], char*id_sala,int num_puzzles)
{
    int existe=67;
    for (int i=0; i<= num_puzzles; i++){
        if (strcmp (puzzles[i]->id_sala, id_sala)==0){  //Si el id de la sala del puzzle coincide con la sala donde esta el jugador, sale del bucle.
            existe =i;
            break;
        }
    } return existe;   
}


void resuelto (Puzzle *puzzles[], int num_puzzles, char*id_sala)
{
    int hay_puzzle = puzzle_sala (puzzles[LENGHT], id_sala, num_puzzles);
    if (hay_puzzle==67){
        printf("No existe puzzles en esta sala");
        return;
    }if (puzzles[hay_puzzle]->resuelto==1)
        printf("El puzzle ya ha sido resuelto");
}
