#include "GestionFichero.h"

// ---------- Registro ----------
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

void cargar_registro(const char *archivo, Registro *r) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Registro.\n", archivo);
        return;
    }
    char linea[256];
    if (fgets(linea, sizeof(linea), f) == NULL) {
        printf("Error al leer línea del archivo %s.\n", archivo);
        fclose(f);
        return;
    }
    fclose(f);
    // Formato: entero-entero-entero-cadena-cadena
    int leidos = sscanf(linea, "%d-%d-%d-%20[^-]-%8[^\n]",
                        &r->Id[0], &r->Id[1], &r->Id[2],
                        r->Nombre, r->Clave);
    if (leidos != 5) {
        printf("Formato incorrecto en el archivo %s.\n", archivo);
    }
}

// ---------- Objeto ----------
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

void cargar_objeto(const char *archivo, Objeto *o) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Objeto.\n", archivo);
        return;
    }
    char linea[256];
    if (fgets(linea, sizeof(linea), f) == NULL) {
        printf("Error al leer línea del archivo %s.\n", archivo);
        fclose(f);
        return;
    }
    fclose(f);
    // Formato: cadena-cadena-cadena-cadena con límites
    int leidos = sscanf(linea, "%4[^-]-%15[^-]-%50[^-]-%30[^\n]",
                        o->id, o->nombre, o->descripcion, o->localizacion);
    if (leidos != 4) {
        printf("Formato incorrecto en el archivo %s.\n", archivo);
    }
}

// ---------- Puzzle ----------
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

void cargar_puzzle(const char *archivo, Puzzle *p) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Puzzle.\n", archivo);
        return;
    }
    char linea[512];
    if (fgets(linea, sizeof(linea), f) == NULL) {
        printf("Error al leer línea del archivo %s.\n", archivo);
        fclose(f);
        return;
    }
    fclose(f);
    // Formato: cadena-cadena-cadena-entero-cadena-cadena-entero
    int leidos = sscanf(linea, "%3[^-]-%15[^-]-%2[^-]-%d-%150[^-]-%50[^-]-%d",
                        p->id, p->nombre, p->id_sala,
                        &p->tipo, p->descripcion, p->solucion, &p->resuelto);
    if (leidos != 7) {
        printf("Formato incorrecto en el archivo %s.\n", archivo);
    }
}
// ---------- Conexion ----------

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
void cargar_conexiones(const char *archivo, Conexion conexiones[], int *num_conexiones) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Conexiones.\n", archivo);
        return;
    }
    char linea[256];
    *num_conexiones = 0;
    while (fgets(linea, sizeof(linea), f) != NULL && *num_conexiones < 100) {
        // Formato: cadena-cadena-cadena
        int leidos = sscanf(linea, "%3[^-]-%3[^-]-%3[^-]-%d-%3[^\n]",
                            conexiones[*num_conexiones].id_conexion_,
                            conexiones[*num_conexiones].id_salaOrigen_,
                            conexiones[*num_conexiones].id_salaDestino_,
                            &conexiones[*num_conexiones].estado_,
                            conexiones[*num_conexiones].id_condicion_);
        if (leidos == 5) {
            (*num_conexiones)++;
        } else {
            printf("Formato incorrecto en el archivo %s en la línea: %s\n", archivo, linea);
        }
    }
    fclose(f);
}
// ---------- Sala ----------

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

void cargar_salas(const char *archivo, Sala salas[], int *num_salas) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo %s para cargar Salas.\n", archivo);
        return;
    }
    char linea[256];
    *num_salas = 0;
    while (fgets(linea, sizeof(linea), f) != NULL && *num_salas < 100) {
        // Formato: cadena-cadena
        int leidos = sscanf(linea, "%3[^-]-%31[^-]-%8[^-]-%151[^\n]",
                            salas[*num_salas].id_sala_,
                            salas[*num_salas].nombre_,
                            &salas[*num_salas].tipo_,
                            salas[*num_salas].descripcion_);
        if (leidos == 4) {
            (*num_salas)++;
        } else {
            printf("Formato incorrecto en el archivo %s en la línea: %s\n", archivo, linea);
        }
    }
    fclose(f);
}

// ---------- Jugador ----------

