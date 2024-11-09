#include<stdio.h>
#include<stdlib.h>

// Estrutura que representa um nó da lista
struct lista {
    int valor; // Este é o valor armazenado no nó (um número inteiro)
    struct lista *prox; // Este é o ponteiro para o próximo nó da lista
};

// Ponteiros globais para gerenciar o começo e o fim da lista
struct lista *aux, *inicio = NULL, *final = NULL;

// Função para inserir um novo número na lista
struct lista* insere() {
    int x;
    printf("Entre com um valor para lista: ");
    scanf("%i", &x); // Lê o valor do usuário

    // Cria um novo nó e aloca espaço na memória para ele
    aux = (struct lista*)malloc(sizeof(struct lista));
    aux->valor = x; // Atribui o valor lido ao novo nó
    aux->prox = NULL; // Define que o próximo nó após este é "nulo" (não há próximo nó ainda)

    // Se a lista estiver vazia, define este novo nó como o início e o final da lista
    if(inicio == NULL) {
        inicio = final = aux;
    } else {
        // Se a lista já tiver elementos, adiciona este nó ao final
        final->prox = aux; // Atualiza o ponteiro do último nó para apontar para o novo nó
        final = aux; // Define o novo nó como o novo final da lista
    }

    return inicio; // Retorna o início da lista (caso tenha mudado)
}

// Função para exibir todos os números na lista
void imprime(struct lista *dados) {
    // Se a lista estiver vazia, exibe uma mensagem
    if(dados == NULL) {
        printf("\nLista Vazia");
    } else {
        aux = dados; // Começa a leitura a partir do início da lista
        while(aux != NULL) { // Continua até chegar ao final (NULL)
            printf("\nDado da lista: %i", aux->valor); // Exibe o valor do nó atual
            aux = aux->prox; // Avança para o próximo nó
        }
    }
}

// Função para excluir um número específico da lista
struct lista* excluir(struct lista* dados, int valor) {
    struct lista *ant = NULL; // Variável para guardar o nó anterior
    int removido;
    aux = dados; // Começa a partir do início da lista
    
    if(dados == NULL) {
        printf("\nLista Vazia");
    } else {
        // Percorre a lista até encontrar o valor ou chegar ao final
        while(aux != NULL && aux->valor != valor) {
            ant = aux; // Guarda o nó atual como "anterior"
            aux = aux->prox; // Avança para o próximo nó
        }
        
        if(aux == NULL) { // Se o valor não foi encontrado
            printf("\nElemento nao encontrado para exclusao");
        } else {
            // Caso especial: se o nó a remover é o primeiro da lista
            if(ant == NULL) {
                removido = aux->valor;
                dados = aux->prox; // Muda o início da lista para o próximo nó
            } else { // Caso o nó a remover não seja o primeiro
                removido = aux->valor;
                ant->prox = aux->prox; // Desconecta o nó atual da lista
            }
            free(aux); // Libera a memória usada pelo nó removido
            printf("\nElemento Removido: %i", removido);
        }
    }
    return dados; // Retorna o início atualizado da lista
}

// Função principal que exibe um menu de opções
int main() {
    int op, remove;
    struct lista *dados = NULL;

    // Menu de opções
    while(op != 4) {
        printf("\nLista Simplesmente Ligada");
        printf("\nDigite 1 para Inserir");
        printf("\nDigite 2 para Imprimir");
        printf("\nDigite 3 para Remover");
        printf("\nDigite 4 para Sair");
        printf("\nEntre com a opcao: ");
        scanf("%i", &op);

        switch(op) {
            case 1: 
                dados = insere(); // Chama a função para inserir um novo valor
                break;
            case 2: 
                imprime(dados); // Chama a função para imprimir todos os valores
                break;
            case 3:
                printf("\nEntre com valor para remover: ");
                scanf("%i", &remove); // Lê o valor a ser removido
                dados = excluir(dados, remove); // Chama a função para remover o valor
                break;
            case 4:
                exit(1); // Encerra o programa
        }
    }
}

