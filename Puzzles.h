#ifndef PUZZLES_H
#define PUZZLES_H
#define LENGHT 10
typedef struct {
    char id [4];  //Identificador del puzzle. 
    char nombre [16]; // Nombre del puzzle.
    char id_sala [3]; // Identificador de la sala donde se encuentra el puzzle.
    int tipo; // 0: Código, 1: Palabra.
    char descripcion [151]; //Descripcion del puzzle con el problema a resolver. 
    char solucion [51]; //Solucion al puzzle.
    int resuelto; //0: sin resolver, 1: resuelto.
} Puzzle;

Puzzle* puzzle_sala (Puzzle *puzzles[], char*id_sala,int num_puzzles);
//Busca si hay algún puzzle en la sala en la que se encuentra el jugador.
void descripcion (Puzzle *p);
//Imprime la descripcion del puzzle junto con su tipo.
int resolver_puzzle(Puzzle *p);
//Comprueba si el puzzle ya está resuelto y en caso de que no lo está comprueba si la respuesta del jugador es correcta.
#endif