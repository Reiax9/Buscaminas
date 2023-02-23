#include "juego.h"


void inicioJuego(int *tablero,int *dificultad){
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    int numInicio;
    numInicio = inicio(MIN,MAX);

    if (numInicio==1)
    {
        *tablero = tableroJuego(MIN,MAX);
        *dificultad = modoJuego(MIN,MAX_MODE);
    }else{
        exit(0);
    }
}

void traspasoValores(int *tamanyo,int *minas){
    int tablero,dificultad;
    inicioJuego(&tablero,&dificultad);

    *tamanyo = (tablero==1) ? MIN_TABLERO :  MAX_TABLERO;

    if (dificultad==1){         *minas = DISNEY;
    }else if (dificultad==2){   *minas = YELLOWSTONE;
    }else{                      *minas = SOMALÍ;
    }
}


void creacionPlantilla(char vector[], int*fila, int*mina){
    int tamanyo,tamanyoDoble,minas,localizacion;
    traspasoValores(&tamanyo,&minas);
    tamanyoDoble = tamanyo*2;
    *fila = tamanyo;
    *mina = minas;
    for (int i = 0; i < tamanyoDoble; i++) //¿ Creamos la plantilla
    {
        vector[i] = (i<tamanyo) ? '?' : '0';
    }
    for (int i = 0; i < minas; i++) //¿ Ponemos las minas
    {
        localizacion = tamanyo + rand()%(tamanyoDoble - tamanyo - 1);
        if(vector[localizacion]=='0') {vector[localizacion] = 'M';}
        else{minas++;}
    }
    for (int i = tamanyo; i < tamanyoDoble; i++) //¿ Colocamos pistas
    {
        if (vector[i]=='0')
        {
            if (vector[i+1]=='M' && vector[i-1]=='M')
            {
                vector[i]='2';

            }else if(vector[i+1]=='M' || vector[i-1]=='M'){
                
                vector[i]='1';
            }
        }
    }
}


void buscaminas(){
    int fila,filaDoble,mina,numeroUsuario,count=1,*vectorComprobar[MAX_TABLERO];
    bool bomba = false;
    char vector[40];

    creacionPlantilla(vector,&fila,&mina);
    filaDoble = fila * 2;

    for (int i = 0; i < fila; i++){
        
        vectorComprobar[i] = 0;
    }
    
    do
    {
        cls();
        printf("Tablero del Juego\n\n");
        for (int i = 0; i < fila; i++)
        {
            printf("%.2d:%c ",i+1,vector[i]);
            
        }
        printf("\n\nCuidado! hay %d minas ocultas\n",mina);
        printf("Indica que casilla quieres descubrir\n");
        do
        {
            printf("Introduce un valor valido:  ");
            scanf("%d",&numeroUsuario);
            printf("\n");
        } while (numeroUsuario<MIN || numeroUsuario>fila || comprobarInput(vectorComprobar,numeroUsuario));
        numeroUsuario--;
        if (vector[numeroUsuario + fila]=='M')
        {
            bomba = true;
        }else if(count + mina == fila){
            break;
        }else{
            vector[(numeroUsuario + fila) - fila] = vector[numeroUsuario + fila];
            count++;
        }
    } while (!bomba);
    
    if (!bomba)
    {
        printf("Eres todo un Rambo esquivando minas!\n\n");
    }else{
        printf("Eso si que son precios explosivos!\n\n");
    }
    printf("Tablero de juego\n\n");
    for (int i = fila; i < filaDoble; i++)
    {
        printf("%.2d:%c ",i-9,vector[i]);
    }
    printf("\n\nPresiona una tecla para continuar");
    getch();
}

bool comprobarInput(int *vectorComprobar,int numeroUsuario){
    int count=0;
    bool result = false;
    
    for (int i = 0; i <= count+1; i++)
    {
       if(vectorComprobar[i]==numeroUsuario){result = true;}
    }
    vectorComprobar[count]=numeroUsuario;
    count++;
    return result;
}