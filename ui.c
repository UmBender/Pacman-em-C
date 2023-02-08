#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};
char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoheroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};


void imprimeParte(char desenho[4][7], int parte){
	printf("%s",desenho[parte]);
}
void imprimeMapa(MAPA* m){
	for (size_t i = 0; i < m->linhas; ++i) {
		for (size_t parte = 0; parte < 4; ++parte) {
			for (size_t j = 0; j < m->colunas; ++j) {
				switch (m->matriz[i][j]) {
					case FANTASMA:
						imprimeParte(desenhofantasma,parte);
						break;
					case HEROI:
						imprimeParte(desenhoheroi,parte);
						break;
					case PILULA:
						imprimeParte(desenhopilula,parte);
						break;

					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						imprimeParte(desenhoparede,parte);
						break;
					case VAZIO:
						imprimeParte(desenhovazio,parte);
						break;
				}
				
			}
			printf("\n");
			
		}
	}
}
