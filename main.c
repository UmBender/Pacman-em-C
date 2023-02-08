// #define NDEBUG // disables assert()
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "header.h"

MAPA m;
void liberaMapa(){
	for (size_t i = 0; i < m.linhas; ++i) {
		free(m.matriz[i]);
	}
	free(m.matriz);
}
void alocaMapa(){
	m.matriz = malloc(sizeof(char*) * m.linhas);
	for (size_t i = 0; i < m.linhas; ++i) {
		m.matriz[i] = malloc(sizeof(char) * (m.colunas+1));
	}
}



void leMapa(){
	FILE* f;
	f = fopen("mapa.txt","r");

	if(f==0){
		printf("Erro na leitura do mapa\n");
		exit(1);
	}


	fscanf(f, "%d %d",&m.linhas, &m.colunas);
	printf("linhas %d colunas %d\n",m.linhas, m.colunas);

	alocaMapa();

	for (size_t i = 0; i < m.linhas; ++i) {
		fscanf(f, "%s",m.matriz[i]);
		
	}
	
	fclose(f);
}

void imprimeMapa(){
	for (size_t i = 0; i < 5; ++i) {
		printf("%s\n",m.matriz[i]);
	}
}

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

	leMapa();

	do {
		imprimeMapa();

		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while(!acabou());


	liberaMapa();
	
	return EXIT_SUCCESS;
}
