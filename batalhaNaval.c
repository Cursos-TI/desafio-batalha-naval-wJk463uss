#include <stdio.h>


#define TabuleiroTAM 10


int main (){

    int tabuleiro[TabuleiroTAM][TabuleiroTAM] = {0};

    printf(" --- TABULEIRO DE BATALHA NAVAL ---\n");
    printf("\n");
    printf("    ");

    // Navio horizontal
    tabuleiro[9][6] = 3;
    tabuleiro[9][7] = 3;
    tabuleiro[9][8] = 3;

    // Navio vertical
    tabuleiro[4][5] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[2][5] = 3;

    // Navios da diagonal
    tabuleiro[0][0] = 3;
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;

    tabuleiro[9][0] = 3;
    tabuleiro[8][1] = 3;
    tabuleiro[7][2] = 3;

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

 return 0;
}