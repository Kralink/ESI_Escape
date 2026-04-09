#include "GestionFichero.h"

// ---------- Registro ----------
/**
 * @brief Guarda un registro de sesión en un archivo de texto.
 *
 * Escribe los campos del registro en una línea con separadores "-".
 * El formato esperado es "Id0-Id1-Id2-Nombre-Clave".
 *
 * @param archivo Nombre o ruta del archivo donde se escribe el registro.
 * @param r Puntero al Registro que se desea guardar.
 * @return void
 */
void guardar_registro(const char *archivo, const Registro *r) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para guardar Registro.\n", archivo);
        return;
    }
    fprintf(f, "%d-%d-%d-%s-%s\n",
            r->Id[0], r->Id[1], r->Id[2],
            r->Nombre, r->Clave);
    fclose(f);
}

/**
 * @brief Carga un registro de sesión desde un archivo de texto.
 *
 * Lee una sola línea del archivo e inicializa un objeto Registro
 * con los campos separados por guiones.
 *
 * @param archivo Nombre o ruta del archivo de origen.
 * @param r Puntero a puntero donde se almacenará el registro cargado.
 * @return void
 */
void cargar_registro(const char *archivo, Registro **r) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Registro.\n", archivo);
        *r = NULL;
        return;
    }
    
    *r = (Registro *)malloc(sizeof(Registro));
    if (*r == NULL) {
        printf("Error al asignar memoria para Registro.\n");
        fclose(f);
        return;
    }
    
    char linea[256];
    if (fgets(linea, sizeof(linea), f) == NULL) {
        printf("Error al leer línea del archivo %s.\n", archivo);
        fclose(f);
        free(*r);
        *r = NULL;
        return;
    }
    fclose(f);
    
    int leidos = sscanf(linea, "%d-%d-%d-%20[^-]-%8[^\n]",
                        &(*r)->Id[0], &(*r)->Id[1], &(*r)->Id[2],
                        (*r)->Nombre, (*r)->Clave);
    if (leidos != 5) {
        printf("Formato incorrecto en el archivo %s.\n", archivo);
        free(*r);
        *r = NULL;
        return;
    }
}

// ---------- Objeto ----------
/**
 * @brief Guarda un objeto en un archivo de texto.
 *
 * Escribe una línea con los datos del objeto separados por guiones.
 * El formato es "id-nombre-descripcion-localizacion".
 *
 * @param archivo Nombre o ruta del archivo donde se escribe el objeto.
 * @param o Puntero al Objeto que se desea guardar.
 * @return void
 */
void guardar_objeto(const char *archivo, const Objeto *o) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para guardar Objeto.\n", archivo);
        return;
    }
    fprintf(f, "%s-%s-%s-%s\n",
            o->id, o->nombre, o->descripcion, o->localizacion);
    fclose(f);
}

/**
 * @brief Carga todos los objetos desde un archivo de texto.
 *
 * Cuenta primero las líneas para reservar el arreglo de Objetos,
 * luego vuelve a leer el archivo y convierte cada línea en un Objeto.
 *
 * @param archivo Nombre o ruta del archivo de origen.
 * @param objetos Puntero a puntero donde se almacenará el arreglo de objetos.
 * @param num_objetos Puntero a entero donde se guardará el número de objetos leídos.
 * @return void
 */
void cargar_objeto(const char *archivo, Objeto **objetos, int *num_objetos) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Objeto.\n", archivo);
        *num_objetos = 0;
        *objetos = NULL;
        return;
    }
    
    // Primer paso: contar el número de líneas
    char linea[256];
    int count = 0;
    while (fgets(linea, sizeof(linea), f) != NULL) {
        count++;
    }
    fclose(f);
    
    // Asignar memoria dinámica
    *objetos = (Objeto *)malloc(count * sizeof(Objeto));
    if (*objetos == NULL) {
        printf("Error al asignar memoria para Objetos.\n");
        *num_objetos = 0;
        return;
    }
    
    // Segundo paso: reabrir el archivo y llenar los datos
    f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al reabrir el archivo %s para cargar Objeto.\n", archivo);
        free(*objetos);
        *objetos = NULL;
        *num_objetos = 0;
        return;
    }
    *num_objetos = 0;
    while (fgets(linea, sizeof(linea), f) != NULL && *num_objetos < count) {
        int leidos = sscanf(linea, "%4[^-]-%15[^-]-%50[^-]-%30[^\n]",
                            (*objetos)[*num_objetos].id,
                            (*objetos)[*num_objetos].nombre,
                            (*objetos)[*num_objetos].descripcion,
                            (*objetos)[*num_objetos].localizacion);
        if (leidos == 4) {
            (*num_objetos)++;
        } else {
            printf("Formato incorrecto en el archivo %s en la línea: %s\n", archivo, linea);
        }
    }
    fclose(f);
}

// ---------- Puzzle ----------
/**
 * @brief Guarda un puzzle en un archivo de texto.
 *
 * Escribe una línea con los campos del puzzle separados por guiones.
 * El formato es "id-nombre-id_sala-tipo-descripcion-solucion-resuelto".
 *
 * @param archivo Nombre o ruta del archivo donde se escribe el puzzle.
 * @param p Puntero al Puzzle que se desea guardar.
 * @return void
 */
void guardar_puzzle(const char *archivo, const Puzzle *p) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para guardar Puzzle.\n", archivo);
        return;
    }
    fprintf(f, "%s-%s-%s-%d-%s-%s-%d\n",
            p->id, p->nombre, p->id_sala,
            p->tipo, p->descripcion, p->solucion, p->resuelto);
    fclose(f);
}

/**
 * @brief Carga todos los puzzles desde un archivo de texto.
 *
 * Cuenta primero las líneas para reservar el arreglo de Puzzles,
 * luego vuelve a leer el archivo y convierte cada línea en un Puzzle.
 *
 * @param archivo Nombre o ruta del archivo de origen.
 * @param puzles Puntero a puntero donde se almacenará el arreglo de puzzles.
 * @param num_puzles Puntero a entero donde se guardará el número de puzzles leídos.
 * @return void
 */
void cargar_puzles(const char *archivo, Puzzle **puzles, int *num_puzles) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Puzles.\n", archivo);
        *num_puzles = 0;
        *puzles = NULL;
        return;
    }
    
    // Primer paso: contar el número de líneas
    char linea[512];
    int count = 0;
    while (fgets(linea, sizeof(linea), f) != NULL) {
        count++;
    }
    fclose(f);
    
    // Asignar memoria dinámica
    *puzles = (Puzzle *)malloc(count * sizeof(Puzzle));
    if (*puzles == NULL) {
        printf("Error al asignar memoria para Puzles.\n");
        *num_puzles = 0;
        return;
    }
    
    // Segundo paso: reabrir el archivo y llenar los datos
    f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al reabrir el archivo %s para cargar Puzles.\n", archivo);
        free(*puzles);
        *puzles = NULL;
        *num_puzles = 0;
        return;
    }
    *num_puzles = 0;
    while (fgets(linea, sizeof(linea), f) != NULL && *num_puzles < count) {
        int leidos = sscanf(linea, "%3[^-]-%15[^-]-%2[^-]-%d-%150[^-]-%50[^-]-%d",
                            (*puzles)[*num_puzles].id,
                            (*puzles)[*num_puzles].nombre,
                            (*puzles)[*num_puzles].id_sala,
                            &(*puzles)[*num_puzles].tipo,
                            (*puzles)[*num_puzles].descripcion,
                            (*puzles)[*num_puzles].solucion,
                            &(*puzles)[*num_puzles].resuelto);
        if (leidos == 7) {
            (*num_puzles)++;
        } else {
            printf("Formato incorrecto en el archivo %s en la línea: %s\n", archivo, linea);
        }
    }
    fclose(f);
}

// ---------- Conexion ----------
/**
 * @brief Guarda una conexión entre salas en un archivo de texto.
 *
 * Escribe los campos de la conexión con separadores "-".
 * El formato esperado es "id_conexion-id_salaOrigen-id_salaDestino-estado-id_condicion".
 *
 * @param archivo Nombre o ruta del archivo donde se escribe la conexión.
 * @param c Puntero a la Conexion que se desea guardar.
 * @return void
 */
void guardar_conexion(const char *archivo, const Conexion *c) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para guardar Conexion.\n", archivo);
        return;
    }
    fprintf(f, "%s-%s-%s-%i-%s\n",
            c->id_conexion_, c->id_salaOrigen_, c->id_salaDestino_, c->estado_, c->id_condicion_);
    fclose(f);
}

/**
 * @brief Carga todas las conexiones desde un archivo de texto.
 *
 * Cuenta antes las líneas para reservar memoria y luego parsea
 * cada línea en una estructura Conexion.
 *
 * @param archivo Nombre o ruta del archivo de origen.
 * @param conexiones Puntero a puntero donde se almacenará el arreglo de conexiones.
 * @param num_conexiones Puntero a entero donde se guardará el número de conexiones leídas.
 * @return void
 */
void cargar_conexiones(const char *archivo, Conexion **conexiones, int *num_conexiones) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Conexiones.\n", archivo);
        *num_conexiones = 0;
        *conexiones = NULL;
        return;
    }
    
    // Primer paso: contar el número de líneas
    char linea[256];
    int count = 0;
    while (fgets(linea, sizeof(linea), f) != NULL) {
        count++;
    }
    fclose(f);
    
    // Asignar memoria dinámica
    *conexiones = (Conexion *)malloc(count * sizeof(Conexion));
    if (*conexiones == NULL) {
        printf("Error al asignar memoria para Conexiones.\n");
        *num_conexiones = 0;
        return;
    }
    
    // Segundo paso: reabrir el archivo y llenar los datos
    f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al reabrir el archivo %s para cargar Conexiones.\n", archivo);
        free(*conexiones);
        *conexiones = NULL;
        *num_conexiones = 0;
        return;
    }
    *num_conexiones = 0;
    while (fgets(linea, sizeof(linea), f) != NULL && *num_conexiones < count) {
        int leidos = sscanf(linea, "%3[^-]-%3[^-]-%3[^-]-%d-%3[^\n]",
                            (*conexiones)[*num_conexiones].id_conexion_,
                            (*conexiones)[*num_conexiones].id_salaOrigen_,
                            (*conexiones)[*num_conexiones].id_salaDestino_,
                            &(*conexiones)[*num_conexiones].estado_,
                            (*conexiones)[*num_conexiones].id_condicion_);
        if (leidos == 5) {
            (*num_conexiones)++;
        } else {
            printf("Formato incorrecto en el archivo %s en la línea: %s\n", archivo, linea);
        }
    }
    fclose(f);
}

// ---------- Sala ----------
/**
 * @brief Guarda una sala en un archivo de texto.
 *
 * Escribe una línea con los datos de la sala separados por guiones.
 * El formato es "id_sala-nombre-tipo-descripcion".
 *
 * @param archivo Nombre o ruta del archivo donde se escribe la sala.
 * @param s Puntero a la Sala que se desea guardar.
 * @return void
 */
void guardar_sala(const char *archivo, const Sala *s) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para guardar Sala.\n", archivo);
        return;
    }
    fprintf(f, "%s-%s-%s-%s\n",
            s->id_sala_, s->nombre_, s->tipo_, s->descripcion_);
    fclose(f);
}

/**
 * @brief Carga todas las salas desde un archivo de texto.
 *
 * Cuenta las líneas primero para reservar memoria y luego carga
 * cada línea en un elemento del arreglo de salas.
 *
 * @param archivo Nombre o ruta del archivo de origen.
 * @param salas Puntero a puntero donde se almacenará el arreglo de salas.
 * @param num_salas Puntero a entero donde se guardará el número de salas leídas.
 * @return void
 */
void cargar_salas(const char *archivo, Sala **salas, int *num_salas) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Salas.\n", archivo);
        *num_salas = 0;
        *salas = NULL;
        return;
    }
    
    // Primer paso: contar el número de líneas
    char linea[256];
    int count = 0;
    while (fgets(linea, sizeof(linea), f) != NULL) {
        count++;
    }
    fclose(f);
    
    // Asignar memoria dinámica
    *salas = (Sala *)malloc(count * sizeof(Sala));
    if (*salas == NULL) {
        printf("Error al asignar memoria para Salas.\n");
        *num_salas = 0;
        return;
    }
    
    f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al reabrir el archivo %s para cargar Salas.\n", archivo);
        free(*salas);
        *salas = NULL;
        *num_salas = 0;
        return;
    }
    *num_salas = 0;
    while (fgets(linea, sizeof(linea), f) != NULL && *num_salas < count) {
        int leidos = sscanf(linea, "%3[^-]-%31[^-]-%8[^-]-%151[^\n]",
                            (*salas)[*num_salas].id_sala_,
                            (*salas)[*num_salas].nombre_,
                            (*salas)[*num_salas].tipo_,
                            (*salas)[*num_salas].descripcion_);
        if (leidos == 4) {
            (*num_salas)++;
        } else {
            printf("Formato incorrecto en el archivo %s en la línea: %s\n", archivo, linea);
        }
    }
    fclose(f);
}


// ---------- Jugador ----------
/**
 * @brief Guarda los datos básicos de un jugador en un archivo.
 *
 * Actualmente solo escribe el nombre del jugador en una línea.
 *
 * @param archivo Nombre o ruta del archivo donde se guarda el jugador.
 * @param jugador Puntero al Jugador que se desea guardar.
 * @return void
 */
void guardar_jugador(const char *archivo, const Jugador *jugador) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para guardar Jugador.\n", archivo);
        return;
    }
    fprintf(f, "%s\n", jugador->Jugador);
    fclose(f);
}

/**
 * @brief Carga un jugador desde un archivo.
 *
 * Lee el nombre del jugador de la primera línea y crea la estructura Jugador.
 * Inicializa el inventario como una cadena vacía y resetea el id de sala.
 *
 * @param archivo Nombre o ruta del archivo de origen.
 * @param jugador Puntero a puntero donde se almacenará el Jugador cargado.
 * @return void
 */
void cargar_jugador(const char *archivo, Jugador **jugador) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Jugador.\n", archivo);
        *jugador = NULL;
        return;
    }

    *jugador = (Jugador *)malloc(sizeof(Jugador));
    if (*jugador == NULL) {
        printf("Error al asignar memoria para Jugador.\n");
        fclose(f);
        return;
    }

    if (fgets((*jugador)->Jugador, sizeof((*jugador)->Jugador), f) == NULL) {
        printf("Error al leer el nombre del jugador del archivo %s.\n", archivo);
        free(*jugador);
        *jugador = NULL;
        fclose(f);
        return;
    }
    fclose(f);

    size_t len = strcspn((*jugador)->Jugador, "\r\n");
    (*jugador)->Jugador[len] = '\0';

    (*jugador)->Id_sala[0] = '\0';
    
    // Asignar memoria dinámica para el inventario
    (*jugador)->Inventario = (char *)malloc(5 * sizeof(char));
    if ((*jugador)->Inventario == NULL) {
        printf("Error al asignar memoria para el Inventario.\n");
        free(*jugador);
        *jugador = NULL;
        return;
    }
    (*jugador)->Inventario[0] = '\0';
}
