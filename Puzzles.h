#ifndef PUZZLES.H
#define PUZZLES.H

typedef struct {
    char id [3];  //Identificador del puzzle 
    char nombre [16]; // Nombre del puzzle
    char id_sala [3]; // Identificador de la sala donde se encuentra el puzzle
    int tipo; // 0: Código, 1: Palabra
    char descripcion [151]; //Descripcion del puzzle con el problema a resolver 
    char solucion [51]; //Solucion al puzzle
} Puzzle;


#endif 