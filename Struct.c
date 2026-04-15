#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float media;
} aluno;

int main() {
    // criando e inicializando uma variavel do tipo aluno
    aluno aluno1 = {"João", 20, 8.5};

    // Acessando os dados com o operador

    printf("aluno: %s\n", aluno1.nome);
    printf("idade: %d\n", aluno1.idade);
    printf("média: %.2f\n", aluno1.media);

    return 0;
}

