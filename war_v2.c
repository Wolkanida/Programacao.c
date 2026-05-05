#include <stdio.h>
#include <stdlib.h> // Para malloc, calloc e free
#include <string.h>
#include <time.h>   // Para os dados aleatórios

// 1. Definição da ficha (struct)
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- MODULARIZAÇÃO: FUNÇÕES ---

// Função para exibir o mapa atual
void exibirMapa(struct Territorio *lista, int n) {
    printf("\n========= SITUAÇÃO DO MAPA =========\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] Território: %-15s | Cor: %-10s | Tropas: %d\n", 
                i + 1, lista[i].nome, lista[i].cor, lista[i].tropas);
    }
    printf("====================================\n");
}

// Função de ataque por turno (Uso de Ponteiros e Seta ->)
void atacar(struct Territorio *atq, struct Territorio *def, char *log) {
    int dadoAtq = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    // Guardando o resultado no Log (espaço alocado via malloc)
    sprintf(log, "ÚLTIMO CONFRONTO: %s (%d) vs %s (%d)", atq->nome, dadoAtq, def->nome, dadoDef);
    printf("\n%s\n", log);

    if (dadoAtq > dadoDef) {
        printf(">>> O atacante venceu a rodada!\n");
        def->tropas--;
    } else {
        printf(">>> O defensor resistiu!\n");
        atq->tropas--;
    }

    // Lógica de Conquista
    if (def->tropas <= 0) {
        printf("\n!!! VITÓRIA: %s conquistou %s !!!\n", atq->nome, def->nome);
        strcpy(def->cor, atq->cor);
        
        // Regra: Transfere metade das tropas (mínimo 1 para o perdedor)
        def->tropas = atq->tropas / 2;
        atq->tropas -= def->tropas;
        
        if (atq->tropas == 0) atq->tropas = 1; // Nunca deixa o atacante zerado
    }
}

int main() {
    int n, op, idAtq, idDef;
    struct Territorio *lista;
    char *logBatalha;

    srand(time(NULL));

    printf("Quantos territórios no jogo? ");
    scanf("%d", &n);

    // --- USO DAS DUAS FUNÇÕES DE ALOCAÇÃO ---
    
    // 1. CALLOC: Para a lista de territórios (limpa a memória)
    lista = (struct Territorio*) calloc(n, sizeof(struct Territorio));

    // 2. MALLOC: Para um buffer de texto do relatório de batalha
    logBatalha = (char*) malloc(100 * sizeof(char));

    // Cadastro
    for (int i = 0; i < n; i++) {
        printf("\nCadastro do Território %d:\n", i + 1);
        printf("Nome: ");    scanf(" %[^\n]s", lista[i].nome);
        printf("Cor: ");     scanf("%s", lista[i].cor);
        printf("Tropas: ");  scanf("%d", &lista[i].tropas);
    }

    // LOOP DE TURNOS
    do {
        exibirMapa(lista, n);
        printf("\nMENU:\n1. Atacar (1 Turno)\n2. Sair\nEscolha: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("ID Atacante: "); scanf("%d", &idAtq);
            printf("ID Defensor: "); scanf("%d", &idDef);

            // Validação operacional
            if (idAtq > 0 && idAtq <= n && idDef > 0 && idDef <= n && idAtq != idDef) {
                if (lista[idAtq-1].tropas > 1) {
                    atacar(&lista[idAtq-1], &lista[idDef-1], logBatalha);
                } else {
                    printf("\n[AVISO] Tropas insuficientes para atacar!\n");
                }
            } else {
                printf("\n[ERRO] Comando inválido!\n");
            }
        }
    } while (op != 2);

    // --- LIBERAÇÃO DE MEMÓRIA (Obrigatório) ---
    free(lista);
    free(logBatalha);

    printf("\nMemória liberada com sucesso. Fim da missão!\n");
    return 0;
}