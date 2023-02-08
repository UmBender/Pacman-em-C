// #define NDEBUG // disables assert()
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "header.h"
#include "mapa.h"
#include <time.h>

MAPA m;
POSICAO heroi;

bool paraOndeFantasmaVai(int xAtual,int yAtual,
	int* xDestino,int* yDestino){

	int opcoes[4][2] ={
		{xAtual, yAtual+1},
		{xAtual+1, yAtual},
		{xAtual, yAtual-1},
		{xAtual-1, yAtual}
	};
	srand(time(0));
	for (size_t i = 0; i < 10; ++i) {
		int posicao = rand()%4;
		
		if(podeAndar(&m,FANTASMA, opcoes[posicao][0],opcoes[posicao][1])){

			*xDestino = opcoes[posicao][0];
			*yDestino = opcoes[posicao][1];

			return true;
		}
		
	}
	return false;
}


void fantasma() {
	MAPA copia;

	copiaMapa(&copia, &m);
	for (size_t i = 0; i < m.linhas; ++i) {
		for (size_t j = 0; j < m.colunas; ++j) {
			
			if (copia.matriz[i][j] == FANTASMA) {
				int xDestino;
				int yDestino;
				bool encontrou = paraOndeFantasmaVai(i,j,&xDestino,&yDestino);
				if(encontrou){
					andaMapa(&m,i,j,xDestino,yDestino);

				}
			}
		}
		
	}
	liberaMapa(&copia);
}
bool acabou() {
	POSICAO pos;
	bool pacmanNoMapa = encontraMapa(&m, &pos, HEROI);
	return !pacmanNoMapa;
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
			proximoY--;

			break;
		case CIMA:
			proximoX--;

			break;
		case BAIXO:
			proximoX++;

			break;
		case DIREITA:
			proximoY++;

			break;
	}
	if (!podeAndar(&m,HEROI,proximoX,proximoY))
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
		fantasma();
	} while(!acabou());


	liberaMapa(&m);
	
	return EXIT_SUCCESS;
}
