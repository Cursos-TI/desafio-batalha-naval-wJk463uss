#include <stdio.h>
#include <stdlib.h>


#define TabuleiroTAM 10
#define HabilidadeTAM 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 1


void Iniciartabuleiro(int tabuleiro[TabuleiroTAM][TabuleiroTAM]) {

    printf(" --- TABULEIRO DE BATALHA NAVAL ---\n");
    printf("\n");
    printf("    ");

    for (int i = 0; i < TabuleiroTAM; i++) 
    {
        printf(" %d  ", i + 1);
    }
        printf("\n");

        char letras[] = "ABCDEFGHIJ"; // Letras para as linhas do tabuleiro

    for (int i = 0; i < TabuleiroTAM; i++) // 
    {
        printf(" %c  ", letras[i]);
        for (int j = 0; j < TabuleiroTAM; j++) 
    {
        printf(" %d  ", tabuleiro[i][j]);
    }
    printf("\n");
   
    }
}

void posicionarNavio(int tabuleiro[TabuleiroTAM][TabuleiroTAM]){
    // Navio horizontal (linha 0, colunas 2-4)
        for (int j = 2; j < 5; j++) {
            tabuleiro[0][j] = NAVIO;
    }
    
    // Navio vertical (coluna 7, linhas 5-7)
        for (int i = 5; i < 8; i++) {
            tabuleiro[i][7] = NAVIO;
    }
    
    // Navio diagonal decrescente (\)
        for (int i = 0; i < 3; i++) {
            tabuleiro[1+i][1+i] = NAVIO;
    }
    
    // Navio diagonal crescente (/)
        for (int i = 0; i < 3; i++) {
            tabuleiro[3+i][7-i] = NAVIO;
    }
    }

// Matrizes de habilidades
int cone[HabilidadeTAM][HabilidadeTAM] = {0};
int cruz[HabilidadeTAM][HabilidadeTAM] = {0};
int octaedro[HabilidadeTAM][HabilidadeTAM] = {0};


void criarHabilidadeCone(int habilidade[HabilidadeTAM][HabilidadeTAM]) {
    int centro = HabilidadeTAM / 2; // Ponto central da matriz
    for (int i = 0; i < HabilidadeTAM; i++)
     {
        for (int j = 0; j < HabilidadeTAM; j++) {
            if (j >= centro - i && j <= centro + i) {
                habilidade[i][j] = HABILIDADE; // valor da habilidade = 1
           
        }
    }
}

}

void criarHabilidadeCruz(int habilidade[HabilidadeTAM][HabilidadeTAM]){
    int centro = HabilidadeTAM / 2;
    for (int i = 0; i < HabilidadeTAM; i++) {
        for (int j = 0; j < HabilidadeTAM; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = HABILIDADE;

            }
        }
    }
}

void criarHabilidadeOctaedro(int habilidade[HabilidadeTAM][HabilidadeTAM]){
    int centro = HabilidadeTAM / 2;
    for (int i = 0; i < HabilidadeTAM; i++) {
        for (int j = 0; j < HabilidadeTAM; j++) {
            if (abs (i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = HABILIDADE; // valor da habilidade = 1
            }
        }
    }

}
void exibirHabilidade(int matriz[HabilidadeTAM][HabilidadeTAM]) {
    for (int i = 0; i < HabilidadeTAM; i++) {
        for (int j = 0; j < HabilidadeTAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TabuleiroTAM][TabuleiroTAM],
                     int habilidade[HabilidadeTAM][HabilidadeTAM],
                     int centroX, int centroY) {
    int offset = HabilidadeTAM / 2; // Deslocamento para o centro da habilidade

    for (int i = 0; i < HabilidadeTAM; i++) {
        for (int j = 0; j < HabilidadeTAM; j++) {
            // Calcular as coordenadas no tabuleiro
            int x = centroX - offset + i;
            int y = centroY - offset + j;
            if (x >= 0 && x < TabuleiroTAM && y >= 0 && y < TabuleiroTAM) {
                if (habilidade[i][j] == HABILIDADE) {
                    tabuleiro[x][y] = HABILIDADE; 
                }
            }
        }
    }
}   



int main (){
    int tabuleiro[TabuleiroTAM][TabuleiroTAM] = {AGUA}; // Inicializa o tabuleiro com 0 (AGUA)


    posicionarNavio(tabuleiro);

    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 3);
    aplicarHabilidade(tabuleiro, octaedro, 4, 7);


    Iniciartabuleiro(tabuleiro);

    return 0;
}