#include "presentacion.h"

int inicio(int min, int max){
    int empezarJuego;
    printf("------------------------------------------------------------------------------\n");
    printf("                  Bienvenivod al juego buscaminas\n");
    printf("         Juego clasico de windows donde explotar no es una opcion\n\n");
    printf("                          By Xavier Garcia\n");
    printf("------------------------------------------------------------------------------\n\n");

    printf("¿Que quieres hacer?\n");
    printf("1) Jugar una partida\n");
    printf("2) Salir\n\n");

    do
    {
        printf("Escoge una opción valida  ");
        scanf("%d",&empezarJuego);
        while(getchar()!='\n');
    } while (empezarJuego<min || empezarJuego>max);

    if (empezarJuego==2){printf("Saliendo del juego...");
    }
    else{ printf("Has escogido jugar\nPresiona una tecla para empezar!");}  

    getch();
    cls();
    return empezarJuego;
}



int tableroJuego(int min, int max){
    int numTabla;
    printf("Escoge el tamaño del tablero\n");
    printf("1) Tablero pequeño: 10 casillas\n");
    printf("2) Tablero grande: 20 casillas\n\n");
    do
    {
        printf("Escoge una opción valida  ");
        scanf("%d",&numTabla);
        while(getchar()!='\n');
    } while (numTabla<min || numTabla>max);

    if (numTabla==1){printf("Has escogido el tablero pequeño\npresiona cualquier tecla para comenzar\n");}
    else{ printf("Has escogido el tablero grande\npresiona cualquier tecla para comenzar\n");}

    getch();
    cls();
    return numTabla;
}

int modoJuego(int min, int max){
    int numJuego;
    printf("Escoge un modo de dificultad\n");
    printf("1) Disney: 2 mines\n");
    printf("2) Yellowstone: 4 mines\n");
    printf("3) Somalí: 6 mines\n\n");

    do
    {
        printf("Escoge una opción valida  ");
        scanf("%d",&numJuego);
        while(getchar()!='\n');
    } while (numJuego<min || numJuego>max);
    
    if (numJuego==1){printf("\nHas escogido el nivel de dificultad Disney!\nPresiona una tecla para seguir\n");
    }else if (numJuego==2){printf("\nHas escogido el nivel de dificultad Yellowstone!\nPresiona una tecla para seguir\n");
    }else{printf("\nHas escogido el nivel de dificultad Somalí!\nPresiona una tecla para seguir\n");}

    getch();
    cls();
    return numJuego;
}
