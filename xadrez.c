#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void movimenta_torre(int casas, char direcao) {
    if(casas > 0) {
        switch (direcao)
        {
        case 'b':
            printf("Baixo\n");
            break;
        case 'c':
            printf("Cima\n");
            break;
        case 'd':
            printf("Direita\n");
            break;
        case 'e':
            printf("Esquerda\n");
            break;
        default:
            printf("Direção inválida!");
            return;
        }

        movimenta_torre(casas - 1, direcao);
    }
}

void movimenta_bispo(int casas, char dir_ver, char dir_hor) {
    if(casas > 0) {
        if((dir_ver == 'b' || dir_ver == 'c') && (dir_hor == 'd' || dir_hor == 'e')) {
            switch (dir_ver)
            {
            case 'b':
                printf("Baixo, ");
                break;
            case 'c':
                printf("Cima, ");
                break;
            }
            switch (dir_hor)
            {
            case 'd':
                printf("Direita\n");
                break;
            case 'e':
                printf("Esquerda\n");
                break;
            }
        } else {
            printf("Direção inválida!");
            return;
        }
        movimenta_bispo(casas - 1, dir_ver, dir_hor);
    }
}

void movimenta_rainha (int casas, char dir_ver, char dir_hor) {
    if(dir_ver == dir_hor) {
        movimenta_torre(casas, dir_ver);
    } else {
        movimenta_bispo(casas, dir_ver, dir_hor);
    }
}


int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.
    const int casas_cavalo[2] = {1, 2};
    int j = 0, k = 0;

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    printf("\n\n---| Movimentação do Bispo |---\n");
    movimenta_bispo(5, 'c', 'd');

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    printf("\n\n---| Movimentação da Torre |---\n");
    movimenta_torre(5, 'd');
    

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    printf("\n\n---| Movimentação da Rainha |---\n");
    movimenta_rainha(8, 'e', 'e'),

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.
    printf("\n\n---| Movimentação do Cavalo |---\n");
    for(int v = 0; v < casas_cavalo[1]; v++) {
        printf("Cima\n");
        if(v == casas_cavalo[1] - 1) {
            for(int h = 0; h < casas_cavalo[0]; h++) {
                printf("Direita\n");
            }
        }
    }

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
