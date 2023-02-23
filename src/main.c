#include <stdio.h>
#include <conio.h>
#include "rlutil.h"
#include "juego.h"



int main(){
	srand(time(NULL));
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	buscaminas();
	
	getch();
	return 0;
}
