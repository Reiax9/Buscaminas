#ifndef A05F468A_6A26_4161_B5EF_84D2E935EA11
#define A05F468A_6A26_4161_B5EF_84D2E935EA11
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdbool.h>
    #include "presentacion.h"
    #define MIN 1
    #define MAX 2
    #define MAX_MODE 3
    #define MIN_TABLERO 10
    #define MAX_TABLERO 20
    #define DISNEY 2
    #define YELLOWSTONE 4
    #define SOMALÍ 6

    void inicioJuego(int*,int*);
    void traspasoValores(int*,int*);
    void creacionPlantilla(char vector[],int*,int*);
    void buscaminas();
    bool comprobarInput(int*,int,int);
#endif /* A05F468A_6A26_4161_B5EF_84D2E935EA11 */
