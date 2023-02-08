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

void move(char direcao){

	if (
			direcao != 'a' &&
			direcao != 's' &&
			direcao != 'd' &&
			direcao != 'w'
	   ) {
		return;
	}


	int proximoX= heroi.x;
	int proximoY= heroi.y;

	switch (direcao) {

		case 'a':
			m.matriz[heroi.x][heroi.y-1] = '@';
			heroi.y--;

			break;
		case 'w':
			m.matriz[heroi.x-1][heroi.y] = '@';
			heroi.x--;

			break;
		case 's':
			m.matriz[heroi.x+1][heroi.y] = '@';
			heroi.x++;

			break;
		case 'd':
			m.matriz[heroi.x][heroi.y+1] = '@';
			heroi.y++;

			break;
	}
	if (proximoX >= m.linhas)
		return;
	if (proximoY >= m.colunas)
		return;
	if (m.matriz[proximoX][proximoY] != '.')
		return;

	m.matriz[proximoX][proximoY] = '@';
	m.matriz[heroi.x][heroi.y] = '.';
	heroi.x = proximoX;
	heroi.y = proximoY;

}

int main(int argc, char *argv[])
{

	leMapa(&m);
	encontraMapa(&m, &heroi, '@');

	do {
		imprimeMapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while(!acabou());


	liberaMapa(&m);
	
	return EXIT_SUCCESS;
}
