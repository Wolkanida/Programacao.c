#include <stdio.h>
#include <stdlib.h> //necessario para malloc e calloc
#include <string.h>
#include <time.h> // necessario uso de tempo (dados aleatorios)

// definição da struct
struct territorio {
    char nome[30];
    char cor[10];
    int tropas
};

// funções de modularização

// função simular o ataque usando ponteiros
void atacar(struct territorio *atacante, struct territorio *defensor) {
    int dadoAtacante = (rand() % 6) + 1; //gera dado de 1 a 6
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n--- BATALHA: %s vs %s ---\n", atacante->nome, defensor->nome);

    if(dadoAtacante > dadoDefensor) {
        printf("Vitoria do Atacante!\n");
        // transfere a cor e metade das tropas
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf(" O defensor resistiu! Atacante perde 1 tropa.\n");
        atacante->tropas--;
    }
}

int main() {
    int n, i;
    struct territorio *lista; //ponteiro para lista dinamica
    
    srand(time(NULL)); //inicializa a semente dos dados aleatorios

    // alocaçao dinamica
    printf("Quantos Territorios deseja registrar? ");
    scanf("%d", &n);

    // Reserva espaço na memoria.
    lista = (struct territorio*) malloc(n * sizeof(struct territorio));

    // Registro cadastro
    for (i = 0; i < n; i++) {
        printf("\n Territorio %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", lista[i].nome);
        printf("Cor: ");
        scanf("%s", lista[i].cor);
        printf("Tropas: ");
        scanf("%d", &lista[i].tropas);
    
    }

    //exemplo de ataque
    if (n >= 2) {
        atacar(&lista[0], &lista[1]);
    }

    // Exibição pós-Ataque
    printf("\n=== ESTADO ATUAL DO MAPA ===\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d | Nome: %-15s | Cor: %-10s | Tropas: %d\n",
                i + 1, lista[i].nome, lista[i].cor, lista[i].tropas);
    }

    // liberar memoria com free
    free(lista);
    printf("\n Memoria Liberada. Fim do programa.\n");

    return 0;
}



