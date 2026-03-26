#include<stdio.h>
#include<conio.h>
#include"Reg_sesion.h"

//el main gestiona luego si lo que introduce por teclado el usuario es correcto
int menu_principal(){
    
    int opcion;

    printf("            ESI ESCAPE\n");
    printf("-------------------------------------\n");
    printf("   1. Nueva partida\n");
    printf("   2. Cargar partida\n");
    printf("   3. Salir\n");
    printf("\n");
    printf("Introduce una de las opciones:\n");
    scanf("%i", &opcion);

    return opcion;
}

//el main gestiona luego si lo que introduce por teclado el usuario es correcto
int menu_juego(){

    int opcion;

    printf("           Sala: %s\n");
    printf("-------------------------------------\n");
    printf(" 1. Describir sala\n");
    printf(" 2. Examinar (objetos y salidas)\n");
    printf(" 3. Entrar en otra sala\n");
    printf(" 4. Coger objeto\n");
    printf(" 5. Soltar objeto\n");
    printf(" 6. Inventario\n");
    printf(" 7. Usar objeto\n");
    printf(" 8. Resolver puzle/introducir codigo\n");
    printf(" 9. Guardar partida\n");
    printf(" 10. Volver\n");
    printf("\n");
    printf("Introduce una de las opciones:\n");
    scanf("%i", &opcion);

    return opcion;
}

//El main gestiona si lo que introduce el usuario es correcto o no
int menu_inicio_juego(){

    int opcion;

    printf("  Bienvenido a ESI ESCAPE\n");
    printf("-----------------------------\n");
    printf("  1. Iniciar sesion\n");
    printf("  2. Registrar jugador\n");
    scanf("%i", &opcion);

    return opcion;
}