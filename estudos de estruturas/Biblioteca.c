//==========================================================================================
// PRATICA: SISTEMA DE BIBLIOTECA - PARTE 1
//
// OBJETIVO DESTA PARTE:
//Implementar o cadastro e a listagem de livros usando um array estatico.
//foco em structs, entrada/saida de dados e organização básica.
//
//
//=========================================================================================

#include <stdio.h>
#include <stdlib.h> //
#include <string.h> // para strcspn()

// --- Constantes Globais ---
#define max_livros 50
#define tam_string 100

// ---  Definição da Estrutura (struct) ---
struct livro {
    char nome[tam_string];
    char autor[tam_string];
    char editora[tam_string];
    int edicao;
};

// --- Função para limpar o buffer de entrada ---
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != 'n' && c != EOF);
}

// Função principal (main) ---
int main() {
    struct livro biblioteca[max_livros];
    int totallivros = 0;
    int opcao;

    // --- Laço Principal do Menu ---
    do{
       
        // Exibe o menu de opções
        printf("===================================\n");
        printf("      BIBLIOTECA - PARTE 1\n");
        printf("===================================\n");
        printf("1 - Cadastrar novo livro.\n");
        printf("2 - Listar todos os livros.\n");
        printf("0 - Sair.\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opção.\n");

        // Lê a opção do usuário.
        scanf("%d", &opcao);
        LimparBufferEntrada(); // limpa o '\n' deixado pelo scanf.

        // --- Processamento da Opção.
        switch (opcao) {
            case 1: // Cadastro de livro.
                printf("--- Cadastro de Novo Livro ---\n\n");

                if (totallivros < max_livros) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totallivros].nome, tam_string, stdin);

                    printf("Digite o Autor: ");
                    fgets(biblioteca[totallivros].autor, tam_string, stdin);

                    printf("Digite a Editora: ");
                    fgets(biblioteca[totallivros].editora, tam_string, stdin);

                    biblioteca[totallivros].nome[strcspn(biblioteca[totallivros].nome, "\n")] = '\0';
                    biblioteca[totallivros].autor[strcspn(biblioteca[totallivros].autor, "\n")] = '\0';
                    biblioteca[totallivros].editora[strcspn(biblioteca[totallivros].editora, "\n")] = '\0';

                    printf("Digite a Editora: ");
                    scanf("%d", &biblioteca[totallivros].edicao);
                    LimparBufferEntrada();

                    totallivros++;
                    // acrescenta mais um no totallivros.

                    printf("\nLivro cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Não é possivel cadastrar mais livros.\n");
                }

                printf("\nPressione Enter para continuar... ");
                getchar(); // Pausa para o usuario ler a mensagem antes de voltar.

                case 2: // Listagem de Livros.
                    printf("--- Lista de Livros Cadastrados ---\n\n");

                    if (totallivros == 0) {
                        printf(" Nemnhum Livro Cadastrado.\n");
                    } else {
                        for (int i = 0; i < totallivros; i++) {
                            printf("--------------------------------------\n");
                            printf("Livro %d\n, i + 1");
                            printf("Nome: %s\n", biblioteca[i].nome);
                            printf("Autor: %s\n", biblioteca[i].autor);
                            printf("Editora: %s\n", biblioteca[i].editora);
                            printf("Edição: %d\n", biblioteca[i].edicao);
                        }
                        printf("------------------------------------------\n");
                    }

                    // pausa
                    // do proximo loop limpar tela.
                    printf("\nPressione Enter para continuar...");
                    getchar();
                    break;

                case 0: // SAIR
                    printf("\nSaindo do sistema...\n");
                    break;
                
                default: // Opção Invalida.
                    printf("\nOpção Invalida!.  Tente novamente.\n");
                    printf("\nPressione Enter para continuar...\n");
                    getchar();
                    break;
        }

    } while (opcao != 0);
    
    return 0; 
}  