#include <stdio.h>

// Trabalho jogo super Trunfo
// declaração de variaveis para as cartas.

int main(){
    
// Carta 1 variaveis.
    char estado1 [50];
    char codigo1 [10];
    char cidade1 [50];
    int  populacao1;
    float area1;
    float pib1;
    int  pturi1;

// Carta 2 Variaveis.
    char estado2 [50];
    char codigo2 [10];
    char cidade2 [50];
    int  populacao2;
    float area2;
    float pib2;
    int  pturi2;

// Entrada de dados das cartas

    printf("Bem Vindo! ao game de super trunfo!!!. \n");
    printf("Insira os dados da 1ª carta.\n");
    printf("Digite o Estado:   \n");
    getchar();
    fgets(estado1, 50, stdin);
    printf("Digite a Inicial do Estado e um numero de 01 á 04 na frente sem espaço: \n");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade:  \n");
    getchar();
    fgets(cidade1, 50, stdin);
    printf("Digite a quantidade da população:  \n");
    scanf("%d", &populacao1);
    printf("Digite a Área em km2:  \n");
    scanf("%f", &area1);
    printf("Digite o valor do PIB:  \n");
    scanf("%f", &pib1);
    printf("Digite a quantidade de pontos turisticos da cidade: \n");
    scanf("%d", &pturi1);
    printf("\n\n");

    //dados carta 2.

    printf("Insira os dados da 2ª carta.\n");
    printf("Digite o Estado:   \n");
    getchar();
    fgets(estado2, 50, stdin);
    printf("Digite a Inicial do Estado e um numero de 01 á 04 na frente sem espaço: \n");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade:  \n");
    getchar();
    fgets(cidade2, 50, stdin);
    printf("Digite a quantidade da população:  \n");
    scanf("%d", &populacao2);
    printf("Digite a Área em km2:  \n");
    scanf("%f", &area2);
    printf("Digite o valor do PIB:  \n");
    scanf("%f", &pib2);
    printf("Digite a quantidade de pontos turisticos da cidade: \n");
    scanf("%d", &pturi2);
    printf("\n\n");

    //Impressao das cartas na tela.

    printf("Dados da 1º Carta: \n");
    printf("Carta 1: \n");
    printf("Estado: %s \n", estado1);
    printf("Codigo: %s \n", codigo1);
    printf("Nome da Cidade: %s \n", cidade1);
    printf("População: %d \n", populacao1);
    printf("Área: %.2f km² \n", area1);
    printf("PIB: %.2f Bilhoes de reais \n", pib1);
    printf("Numero de pontos turisticos: %d \n", pturi1);
    printf("\n\n");

    printf("Dados da 2º Carta: \n");
    printf("Carta 2º: \n");
    printf("Estado: %s \n", estado2);
    printf("Codigo: %s \n", codigo2);
    printf("Nome da Cidade: %s \n", cidade2);
    printf("População: %d \n", populacao2);
    printf("Área: %.2f km² \n", area2);
    printf("PIB: %.2f Bilhoes de reais \n", pib2);
    printf("Numero de pontos turisticos: %d \n", pturi2);
    printf("\n\n");

    return 0;
