#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX_PLACA 10

// Estrutura de um no para representar cada veiculo
typedef struct No {
    char placa[TAMANHO_MAX_PLACA];
    struct No* proximo;
} No;

// Funcao para criar um novo no
No* criarNo(char* placa) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->placa, placa);
    novoNo->proximo = NULL;
    return novoNo;
}

// Funcao para adicionar um veiculo a pilha (empilhar)
void empilhar(No** pilha, char* placa) {
    No* novoNo = criarNo(placa);
    novoNo->proximo = *pilha;
    *pilha = novoNo;
    printf("Veiculo %s entrou no estacionamento.\n", placa);
}

// Funcao para remover um veiculo da pilha (desempilhar)
void desempilhar(No** pilha, char* placa) {
    if (*pilha == NULL) {
        strcpy(placa, "");  // Caso a pilha esteja vazia
        return;
    }
    No* temp = *pilha;
    strcpy(placa, temp->placa);  // Copiando a placa antes de desalocar o no
    *pilha = (*pilha)->proximo;
    free(temp);
}

// Funcao para remover um veiculo especifico
void removerVeiculo(No** estacionamento, No** patio, char* placa) {
    char placaTemp[TAMANHO_MAX_PLACA];

    // Mover veiculos para o patio ate encontrar o veiculo desejado
    while (*estacionamento != NULL && strcmp((*estacionamento)->placa, placa) != 0) {
        desempilhar(estacionamento, placaTemp);
        empilhar(patio, placaTemp);
        printf("Movendo veiculo %s do estacionamento para o patio.\n", placaTemp);
    }

    // Verifica se o veiculo foi encontrado
    if (*estacionamento == NULL) {
        printf("Veiculo %s nao encontrado no estacionamento.\n", placa);
    } else {
        printf("Veiculo %s saiu do estacionamento.\n", placa);
        desempilhar(estacionamento, placaTemp);
    }

    // Retorna os veiculos do patio para o estacionamento
    while (*patio != NULL) {
        desempilhar(patio, placaTemp);
        empilhar(estacionamento, placaTemp);
        printf("Retornando veiculo %s do patio para o estacionamento.\n", placaTemp);
    }
}

// Funcao para mostrar o estado atual de uma pilha
void mostrarPilha(No* pilha, char* nome) {
    printf("Estado da pilha %s: ", nome);
    if (pilha == NULL) {
        printf("vazia\n");
    } else {
        No* atual = pilha;
        while (atual != NULL) {
            printf("%s ", atual->placa);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

// Funcao principal
int main() {
    No* estacionamento = NULL;
    No* patio = NULL;
    int opcao, n, i;
    char placa[TAMANHO_MAX_PLACA];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Entrada de veiculo\n");
        printf("2 - Saida de veiculo\n");
        printf("3 - Mostrar estado atual\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos veiculos deseja inserir? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Digite a placa do veiculo: ");
                    scanf("%s", placa);
                    empilhar(&estacionamento, placa);
                }
                break;
            case 2:
                printf("Quantos veiculos deseja remover? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Digite a placa do veiculo a ser removido: ");
                    scanf("%s", placa);
                    removerVeiculo(&estacionamento, &patio, placa);
                }
                break;
            case 3:
                mostrarPilha(estacionamento, "Estacionamento");
                mostrarPilha(patio, "Patio");
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
