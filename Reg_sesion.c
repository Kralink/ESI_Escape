#include<stdio.h>
#include<string.h>
#include"Reg_sesion.h"

int inicio_sesion(Registro reg[]);
void realizar_reg(Registro reg[]);

int inicio_sesion(Registro reg[]){               //los parametros los tengo que estudiar todavía


     char id_intro[3], nombre_intro[21], clave_intro[9];
     int condicion_loop=1, condicion_id=0, condicion_nombre=0, condicion_clave=0, condicion_if_loop=0, repetir=0;

     while(condicion_loop==1){
          //se introduce el id de usuario
          printf("Introduce el id de jugador:\n");
          fgets(id_intro, 3, stdin);

          //se introduce el nombre de usuario
          printf("Introduce el nombre de usuario:\n");
          fgets(nombre_intro, 21, stdin);

          //se introduce la contrasena del usuario
          printf("Introduce la clave:\n");
          fgets(clave_intro, 9, stdin);

          int lengh = sizeof(reg);

          //comprobamos que coinciden los parametros del usuario
          for(int n=1; n<=lengh; n++){
               condicion_id=0;
               condicion_nombre=0;
               condicion_clave=0;
               if(strcmp(id_intro, reg[n].Id)==0)
                    condicion_id=1;
               if(strcmp(nombre_intro, reg[n].Nombre)==0)
                    condicion_nombre=1;
               if(strcmp(clave_intro, reg[n].Clave)==0)
                    condicion_clave=1;
               if(condicion_id==1 || condicion_nombre==1 || condicion_clave==1){
                    condicion_loop=0;
                    break;
               }
          }
          if(condicion_loop==0){
               break;
          }
          printf("Los datos introducidos no son correctos, ¿quieres introducir los datos de nuevo o salir del inicio de sesion?: marque 1 para introducir datos o 2 para salir\n ");
          scanf("%i", &repetir);
          if(repetir==2)
          break;
     }
     //se ha iniciado correctamente sesion
     if(condicion_loop==0)
          return 1;
     //no se ha iniciado sesion pero el usuario ha elegido salir
     return 0;
}

void realizar_reg(Registro **reg, int *n){

     char id_intro[3], nombre_intro[21], clave_intro[9];
     int condicion_name=1;

     printf("Introduce un nombre:\n");
     fgets(nombre_intro, 21, stdin);
     for(int m=0; n<=(*n); m++){
          if(strcmp(nombre_intro, (*reg)[m].Nombre)==0){
               condicion_name=0;
               break;
          }
     }
     if(condicion_name==0)
          printf("Has un nombre ya existente\n");
     else{
          Registro *tmp=realloc(*reg, (*n+1) * sizeof(Registro));
          if (tmp!=NULL) {
          *reg = tmp;
          }
     }
}