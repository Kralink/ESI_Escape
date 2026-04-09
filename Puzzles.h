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
//Cabecera: Puzzle* puzzle_sala (Puzzle *puzzles[], char*id_sala,int num_puzzles)
//Precondición: El jugador tiene que estar en una sala.
//Postcondición: Devuelve el puzle que hay en la sala en la que se encuentra el jugador (o NULL si no hay)
Puzzle* puzzle_sala (Puzzle *puzzles[], char*id_sala,int num_puzzles);
//Cabecera: void descripcion (Puzzle *p)
//Precondición: Recibe el puntero a un puzle
//Postcondición: Imprime la descripción del puzle junto a su tipo
void descripcion (Puzzle *p);
//Cabecera: int resolver_puzzle(Puzzle *p)
//Precondición: Recibe el puntero a un puzle
//Postcondición: Devuelve 1 si se resuelve o 0 si no se resuelve
int resolver_puzzle(Puzzle *p);
#endif