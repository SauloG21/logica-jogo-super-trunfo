#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Apresentação do jogo

int main() {
     printf("=====================================\n");
    printf("      BEM-VINDO AO SUPER TRUNFO!     \n");
    printf("=====================================\n");
    printf("Desafie o computador e veja quem tem a melhor carta!\n\n");
    printf("A SUA CARTA JÁ VEM DE FORMA ALEATÓRIA!\n");

    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    // Lista de países disponíveis
    char *paises[] = {"Brasil", "Estados Unidos", "China", "Rússia", "França", "Alemanha", "Japão", "Índia", "Argentina", "Reino Unido"};
    int total_paises = sizeof(paises) / sizeof(paises[0]);
    
    // Escolha aleatória de países para o jogador e o computador
    int indiceJogador = rand() % total_paises;
    int indiceComputador;
    do {
        indiceComputador = rand() % total_paises;
    } while (indiceComputador == indiceJogador);
    
    // Atributos das cartas
    int populacaoJogador = rand() % 100 + 1;
    int populacaoComputador = rand() % 100 + 1;
    float areaJogador = (rand() % 5000 + 100) / 10.0;
    float areaComputador = (rand() % 5000 + 100) / 10.0;
    float pibJogador = (rand() % 10000 + 1000) / 10.0;
    float pibComputador = (rand() % 10000 + 1000) / 10.0;
    int pontosTuristicosJogador = rand() % 10 + 1;
    int pontosTuristicosComputador = rand() % 10 + 1;
    float densidadeJogador = populacaoJogador / areaJogador;
    float densidadeComputador = populacaoComputador / areaComputador;
    
    // Exibir as cartas
    printf("Sua carta: %s\n", paises[indiceJogador]);
    printf("1. População: %d\n", populacaoJogador);
    printf("2. Área: %.1f\n", areaJogador);
    printf("3. PIB: %.1f\n", pibJogador);
    printf("4. Pontos Turísticos: %d\n", pontosTuristicosJogador);
    printf("5. Densidade Demográfica: %.2f\n", densidadeJogador);
    
    printf("\nComputador escolheu: %s\n", paises[indiceComputador]);
    printf("(Os atributos do computador estão ocultos até a comparação!)\n\n");
    
    // Escolha do atributo
    int escolha;
    printf("Escolha um atributo para comparar (1-5): ");
    scanf("%d", &escolha);
    
    float valorJogador, valorComputador;
    char atributo[30];
    int vencedor = 0; // 1 para jogador, -1 para computador, 0 empate
    
    switch (escolha) {
        case 1:
            valorJogador = populacaoJogador;
            valorComputador = populacaoComputador;
            sprintf(atributo, "População");
            vencedor = (valorJogador > valorComputador) ? 1 : (valorJogador < valorComputador) ? -1 : 0;
            break;
        case 2:
            valorJogador = areaJogador;
            valorComputador = areaComputador;
            sprintf(atributo, "Área");
            vencedor = (valorJogador > valorComputador) ? 1 : (valorJogador < valorComputador) ? -1 : 0;
            break;
        case 3:
            valorJogador = pibJogador;
            valorComputador = pibComputador;
            sprintf(atributo, "PIB");
            vencedor = (valorJogador > valorComputador) ? 1 : (valorJogador < valorComputador) ? -1 : 0;
            break;
        case 4:
            valorJogador = pontosTuristicosJogador;
            valorComputador = pontosTuristicosComputador;
            sprintf(atributo, "Pontos Turísticos");
            vencedor = (valorJogador > valorComputador) ? 1 : (valorJogador < valorComputador) ? -1 : 0;
            break;
        case 5:
            valorJogador = densidadeJogador;
            valorComputador = densidadeComputador;
            sprintf(atributo, "Densidade Demográfica");
            vencedor = (valorJogador < valorComputador) ? 1 : (valorJogador > valorComputador) ? -1 : 0; // Invertido
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }
    
    // Mostrar resultado
    printf("\nComparação de cartas (%s):\n", atributo);
    printf("%s: %.2f\n", paises[indiceJogador], valorJogador);
    printf("%s: %.2f\n", paises[indiceComputador], valorComputador);
    
    if (vencedor == 1) {
        printf("\nVocê venceu!\n");
    } else if (vencedor == -1) {
        printf("\nO computador venceu!\n");
    } else {
        printf("\nEmpate!\n");
    }
    
    return 0;
}
