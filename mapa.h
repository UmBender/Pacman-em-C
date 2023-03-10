#ifndef _MAPA_H_

#define _MAPA_H_
#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'
struct mapa
{
	char** matriz;
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

struct posicao
{
	int x;
	int y;
};

typedef struct posicao POSICAO;

void liberaMapa(MAPA* m);
void leMapa(MAPA* m);
void alocaMapa(MAPA* m);
void imprimeMapa(MAPA* m);
bool encontraMapa(MAPA*m, POSICAO* p, char c);
bool ehValida(MAPA* m, int x, int y);
bool ehVazia(MAPA* m, int x, int y);
void andaMapa(MAPA* m,int xOrigem, int yOrigem,int xDestino, int yDestino);
void copiaMapa(MAPA* destino, MAPA* origem);
bool podeAndar(MAPA*m,char personagem, int x, int y);
bool ehParede(MAPA* m, int x, int y);
bool ehPersonagem(MAPA* m,char personagem,int x, int y);
void explodePilula();
void explodePilula2(int x, int y,int somaX,int somaY, int qtd);

#endif // !_MAPA_H_
