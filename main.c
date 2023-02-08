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
	int x;
	int y;

	for (size_t i = 0; i < m.linhas; ++i) {
		for (size_t j = 0; j < m.colunas; ++j) {
			if(m.matriz[i][j] == '@') {
				x = i;
				y = j;
				break;
			}
			
		}
		
	}
	switch (direcao) {

		case 'a':
			m.matriz[x][y-1] = '@';

			break;
		case 'w':
			m.matriz[x-1][y] = '@';

			break;
		case 's':
			m.matriz[x+1][y] = '@';

			break;
		case 'd':
			m.matriz[x][y+1] = '@';

			break;
	}
	m.matriz[x][y] = '.';

}

int main(int argc, char *argv[])
{

	leMapa(&m);

	do {
		imprimeMapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while(!acabou());


	liberaMapa(&m);
	
	return EXIT_SUCCESS;
}
