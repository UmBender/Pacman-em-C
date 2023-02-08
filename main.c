// #define NDEBUG // disables assert()
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "header.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

bool acabou() {
	return false;
}

bool ehDirecao(char direcao){
	return  direcao == 'a' ||
			direcao == 's' ||
			direcao == 'd' ||
			direcao == 'w';
}

void move(char direcao){

	if (!ehDirecao(direcao)) {
		return;
	}


	int proximoX= heroi.x;
	int proximoY= heroi.y;

	switch (direcao) {

		case ESQUERDA:
			m.matriz[heroi.x][heroi.y-1] = '@';
			heroi.y--;

			break;
		case CIMA:
			m.matriz[heroi.x-1][heroi.y] = '@';
			heroi.x--;

			break;
		case BAIXO:
			m.matriz[heroi.x+1][heroi.y] = '@';
			heroi.x++;

			break;
		case DIREITA:
			m.matriz[heroi.x][heroi.y+1] = '@';
			heroi.y++;

			break;
	}
	if (!ehValida(&m,proximoX,proximoY))
		return;
	if (!ehVazia(&m,proximoX,proximoY))
		return;

	andaMapa(&m, heroi.x,heroi.y, proximoX, proximoY);	
	heroi.x = proximoX;
	heroi.y = proximoY;
}

int main(int argc, char *argv[])
{

	leMapa(&m);
	encontraMapa(&m, &heroi,HEROI);

	do {
		imprimeMapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while(!acabou());


	liberaMapa(&m);
	
	return EXIT_SUCCESS;
}
