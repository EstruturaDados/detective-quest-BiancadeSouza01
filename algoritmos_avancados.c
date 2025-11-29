#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
    struct No* sair;
} No;

No* criarNo(char* valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novoNo->valor, valor);
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->sair = NULL;
    return novoNo;
}

No* inserirNO(No* raiz, char* valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    int comp = strcmp(valor, raiz->valor);

    if (comp < 0) {
        raiz->esquerda = inserirNO(raiz->esquerda, valor);
    } 
    else if (comp > 0) {
        raiz->direita = inserirNO(raiz->direita, valor);
    } 
    else {  
        raiz->sair = inserirNO(raiz->sair, valor);
    }

    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
        preOrdem(raiz->sair);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
        emOrdem(raiz->sair);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        posOrdem(raiz->sair);
        printf("%s ", raiz->valor);
    }
}

void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        liberar(raiz->sair);
        free(raiz);
    }
}

int main() {
    No* raiz = NULL;

    raiz = inserirNO(raiz, "Hall entrada");
    raiz = inserirNO(raiz, "Sala de estar");
    raiz = inserirNO(raiz, "Biblioteca");
    raiz = inserirNO(raiz, "Quarto");
    raiz = inserirNO(raiz, "Cozinha");
    raiz = inserirNO(raiz, "Banheiro");

    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    int escolha;

    do {
        printf("\nHALL DA ENTRADA\n");
        printf("1 - Esquerda (Sala de Estar)\n");
        printf("2 - Direita (Biblioteca)\n");
        printf("0 - Sair da casa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
    
        if (escolha == 1) {
            printf("Você está na Sala de Estar\n");
        } 
        else if (escolha == 2) {
            printf("Você está na Biblioteca\n");
        } 
        else if (escolha == 0) {
            printf("Saindo da casa...\n");
        } 
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    
    } while (escolha != 0);

    return 0;

}    