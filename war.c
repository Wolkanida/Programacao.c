#include <stdio.h> //Biblioteca de entrada e saída (printf/scanf)
#include <string.h> // Biblioteca para lidar com textos

// 1. Definição da ficha (struct)
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    int i;
    // 2. Criando o vetor (a gaveta com 5 fichas)
    struct Territorio lista[5];

    // 3. Laço para entrada de dados.
    printf("--- Cadastro de Territorios ---\n");
    for (i = 0; i <5; i++) {
        printf("\n Territorio %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]s", lista[i].nome); // O espaço antes do % ajuda a não pular linha

        printf("Cor do exercito: ");
        scanf("%s", lista[i].cor);

        printf("Quantidade de Tropas: ");
        scanf("%d", &lista[i].tropas);

        printf("\n");
    }

    //4. Laço para exibição

    printf("=====================================\n");
    printf("     RELATORIO DE TERRITORIOS        \n");
    printf("=====================================\n");

    for (i = 0; i < 5; i++) {
        //Exibe os dados formatados.
        
        printf("ID: %d | Nome: %-15s | Cor: %-10s | Tropas: %d\n",
                i + 1, lista[i].nome, lista[i].cor, lista[i].tropas);
    }

    printf("=====================================\n");

    return 0;
}



