#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

bool acabou();
void move(char direcao);
bool ehDirecao(char direcao);
bool paraOndeFantasmaVai(int xAtual,int yAtual,int* xDestino,int* yDestino);

