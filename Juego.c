#include<stdio.h>
#include<conio.h>
#include"Reg_sesion.h"

int main(){

    int opcion1=0, opcion2=0, opcion3=0, lengh, i=1;

     opcion1=menu_inicio_juego();
        
    switch(opcion1){
        case 1: inicio_sesion(reg[]);break;
        case 2: realizar_reg(&reg[], &lengh);break; //lengh es la longitud del array de registros
    }

    while(i==1){
        opcion2=menu_principal();
        switch(opcion2){
            case 1: gameplay(menu_juego);break; //hace falta funcion para borrar datos de partida.txt
            case 2: gameplay(menu_juego);break; //hace falta funcion para cargar datos de partida.txt
            case 3: i=0;break;
        }
    }

    return 0;
}

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

pantalla_final(){

    printf("¡¡¡Has superado ESI ESCAPE!!!\n");
    printf("Esperamos que te haya gustado\n");

}

void gameplay(int (*func)){ //hay que ver que parámetros meter

    int opcion=0, z=0;
    char confirmacion;

    while(opcion=!10 && confirmacion=='S'){
        opcion=func;

        switch(opcion){
            case 1:   ;break; //se imprime por pantalla descp de la sala actual
            case 2: examinar_objetos(&objetos, id_sala, num_objetos);break; //se imprime por pantalla los obj y salidas existentes en la sala (función compañero)
            case 3:   ;break; //se elige una salida posible (desbloqueada) 
            case 4: cambiar_localizacion(&obj, "inventario");break; //se coge un obj de la sala actual (función compañero)
            case 5: cambiar_localizacion(&obj, id_sala);break; //se suelta un obj en la sala actual (función compañero)
            case 6:   ;break; //se imprime por pantalla el actual inventario del jugador (función compañero)
            case 7:     
                z=usar_objeto(&objeto, id_sala);
                //funcion luis;
                break; //se usa un objeto del inventario (función compañero)
            case 8:   ;break; //se resuelve un puzzle de la sala actual si es que hay o se introduce un código (función compañero)
            case 9:   ;break; //se guardan los datos actuales de la partida (función compañero)
            case 10: 
                printf("¿Seguro que quieres salir? Se perderán los datos no guardados: S/N\n");
                scanf("%C", &confirmacion)
                ;break; //salir

        }
        //if(sala==...){
            //opcion=10;
            //confirmacion='S';
            //pantalla_final();
        //}
    }

}