#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {
    char *nome;
    char *isbn;
    float preco;
    int score;
    char *editora;
};

typedef struct Livro tLivro, *pLivro;

//alocar o vetor de sLivro (struct)
pLivro livro_aloc(int qtde);
//usuario insere os dados
void livro_ler(pLivro livros, int qtde);
//exibe a informação de todos os livros armazenados no vetor
void livro_exibe(pLivro livros, int qtde);
//libera a memoria alocada
void livro_desaloca(pLivro livros, int qtde);

int main() {
    int qtde;
    scanf("%d", &qtde);
    getchar();

    pLivro livros = livro_aloc(qtde);
    livro_ler(livros, qtde);
    livro_exibe(livros, qtde);
    livro_desaloca(livros, qtde);

    return 0;
}

//alocar o vetor de sLivro (struct)
pLivro livro_aloc(int qtde) {
    pLivro livros = (pLivro)malloc(qtde * sizeof(tLivro)); //aloca a qntde de livros
    if(livros == NULL) {
        printf("Erro ao alocar a quantidade de livros.\n");
        exit (1);
    }
    return livros; //retorna o ponteiro
}

//inserir os dados dos livros
void livro_ler(pLivro livros, int qtde) {
    char buffer[100]; //buffer temporário para as strings

    for(int i = 0; i < qtde; i++) {
        scanf("%99[^\n]", buffer);
        getchar(); 
        livros[i].nome = (char*)malloc((strlen(buffer) + 1) * sizeof(char)); //aloca a memoria para o nome do livro
        if(livros[i].nome == NULL) {
            printf("Erro ao alocar memoria para o nome do livro.\n");
            exit(1);
        }
        strcpy(livros[i].nome, buffer);

        //lendo o ISBN do livro
        scanf("%99[^\n]", buffer);
        getchar();
        livros[i].isbn = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if(livros[i].isbn == NULL) {
            printf("Erro ao alocar memoria para o ISBN.\n");
        }
        strcpy(livros[i].isbn, buffer);

        //le o preco do livro
        scanf("%f", &(livros[i].preco));
        getchar();
        //le o score do livro
        scanf("%d", &(livros[i].score));
        getchar();

        //lê a editora do livro
        scanf("%99[^\n]", buffer);
        getchar();
        livros[i].editora = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if(livros[i].editora == NULL) {
            printf("Erro ao alocar memoria para a editora do livro.\n");
            exit(1);
        }
        strcpy(livros[i].editora, buffer);
    }
}

//função para exibir os dados dos livros
void livro_exibe(pLivro livros, int qtde) {
    for(int i = 0; i < qtde; i++){
        printf("\nLivro %d:\n", i+1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preco: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
    }
}

//desaloca a memoria alocada
void livro_desaloca(pLivro livros, int qtde) {
    for(int i = 0; i < qtde; i++) {
        free(livros[i].nome); //libera a memoria alocada para o nome
        free(livros[i].isbn); //libera a memoria alocada para o isbnC
        free(livros[i].editora); //libera a memoria alocada para a editora
    }
    free(livros); //libera o vetor livros
}