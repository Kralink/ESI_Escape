#ifndef JUEGO_H
#define JUEGO_H

//Cabecera: int menu_inicio_juego()
//Precondición: iniciar el juego
//Postcondición: menú de registro o inicio de sesión impreso por pantalla
int menu_inicio_juego();

//Cabecera: int menu_principal();
//Precondición: haber realizado el inicio sesión
//Postcondición: imprime por pantalla menú de inicio o carga de partida
int menu_principal();

//Cabecera: int menu_juego()
//Precondición: haber iniciado una partida
//Postcondición: imprime por pantalla el menú de la partida
int menu_juego();

//Cabecera: void gameplay(int (*func))
//Precondición: 
//Postcondición:
void gameplay(int (*func));

//Cabecera: void guardar_partida()
//Precondición: haber pulsado la opción 9 del menú de juego
//Postcondición: se guardan en el fichero partida.txt los cambios no guardados
void guardar_partida();

#endif