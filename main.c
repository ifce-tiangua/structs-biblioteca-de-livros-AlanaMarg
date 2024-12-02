#include <stdio.h>
#include <stdlib.h>

struct Livro {
    char *nome;
    char isbn[20];
    float preco;
    int score;
    char editora[20];
};

typedef struct Livro* pLivro;

pLivro livro_aloc(int qtde) {
    pLivro livros = (pLivro)malloc(qtde * sizeof(struct Livro));
    if (livros == NULL) {
        exit(1);
    }
    return livros;
}

void livro_ler(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        livros[i].nome = (char *)malloc(100 * sizeof(char));
        if (livros[i].nome == NULL) {
            exit(1);
        }
        getchar();
        scanf(" %[^\n]", livros[i].nome);
        scanf(" %s", livros[i].isbn);
        scanf("%f", &livros[i].preco);
        scanf("%d", &livros[i].score);
        getchar();
        scanf(" %[^\n]", livros[i].editora);
    }
}

void livro_exibe(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
    }
}

void livro_desaloca(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        free(livros[i].nome);
    }
    free(livros);
}

int main() {
    int qtde;
    scanf("%d", &qtde);
    pLivro livros = livro_aloc(qtde);
    livro_ler(livros, qtde);
    livro_exibe(livros, qtde);
    livro_desaloca(livros, qtde);
    return 0;
}
