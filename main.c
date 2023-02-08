// #define NDEBUG // disables assert()
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "header.h"


int linhas;
int colunas;
char** mapa;

void liberaMapa(){
	for (size_t i = 0; i < linhas; ++i) {
		free(mapa[i]);
	}
	free(mapa);
}
void alocaMapa(){
	mapa = malloc(sizeof(char*) * linhas);
	for (size_t i = 0; i < linhas; ++i) {
		mapa[i] = malloc(sizeof(char) * (colunas+1));
	}
}



void leMapa(){
	FILE* f;
	f = fopen("mapa.txt","r");

	if(f==0){
		printf("Erro na leitura do mapa\n");
		exit(1);
	}


	fscanf(f, "%d %d",&linhas, &colunas);
	printf("linhas %d colunas %d\n",linhas, colunas);

	alocaMapa();

	for (size_t i = 0; i < linhas; ++i) {
		fscanf(f, "%s",mapa[i]);
		
	}
	
	fclose(f);
}

int main(int argc, char *argv[])
{

	leMapa();

	for (size_t i = 0; i < 5; ++i) {
		printf("%s\n",mapa[i]);
	}


	liberaMapa();
	
	return EXIT_SUCCESS;
}
