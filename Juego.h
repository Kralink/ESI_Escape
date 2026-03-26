#ifndef JUEGO_H
#define JUEGO_H

//Imprime el primer menú para que el jugador elija si quiere iniciar sesión o registrarse
int menu_inicio_juego();

//Muestra el menú con las opciones de nueva partida, continuar una partida o salir, saliendo del juego
int menu_principal();

//Es el menú que se muestra durante el gameplay, mostrando todas las funciones que puede hacer el jugador durante el juego
int menu_juego();

void guardar_partida();

#endif