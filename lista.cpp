#include<stdio.h>
#include<stdlib.h>

// Estrutura que representa um n� da lista
struct lista {
    int valor; // Este � o valor armazenado no n� (um n�mero inteiro)
    struct lista *prox; // Este � o ponteiro para o pr�ximo n� da lista
};

// Ponteiros globais para gerenciar o come�o e o fim da lista
struct lista *aux, *inicio = NULL, *final = NULL;

// Fun��o para inserir um novo n�mero na lista
struct lista* insere() {
    int x;
    printf("Entre com um valor para lista: ");
    scanf("%i", &x); // L� o valor do usu�rio

    // Cria um novo n� e aloca espa�o na mem�ria para ele
    aux = (struct lista*)malloc(sizeof(struct lista));
    aux->valor = x; // Atribui o valor lido ao novo n�
    aux->prox = NULL; // Define que o pr�ximo n� ap�s este � "nulo" (n�o h� pr�ximo n� ainda)

    // Se a lista estiver vazia, define este novo n� como o in�cio e o final da lista
    if(inicio == NULL) {
        inicio = final = aux;
    } else {
        // Se a lista j� tiver elementos, adiciona este n� ao final
        final->prox = aux; // Atualiza o ponteiro do �ltimo n� para apontar para o novo n�
        final = aux; // Define o novo n� como o novo final da lista
    }

    return inicio; // Retorna o in�cio da lista (caso tenha mudado)
}

// Fun��o para exibir todos os n�meros na lista
void imprime(struct lista *dados) {
    // Se a lista estiver vazia, exibe uma mensagem
    if(dados == NULL) {
        printf("\nLista Vazia");
    } else {
        aux = dados; // Come�a a leitura a partir do in�cio da lista
        while(aux != NULL) { // Continua at� chegar ao final (NULL)
            printf("\nDado da lista: %i", aux->valor); // Exibe o valor do n� atual
            aux = aux->prox; // Avan�a para o pr�ximo n�
        }
    }
}

// Fun��o para excluir um n�mero espec�fico da lista
struct lista* excluir(struct lista* dados, int valor) {
    struct lista *ant = NULL; // Vari�vel para guardar o n� anterior
    int removido;
    aux = dados; // Come�a a partir do in�cio da lista
    
    if(dados == NULL) {
        printf("\nLista Vazia");
    } else {
        // Percorre a lista at� encontrar o valor ou chegar ao final
        while(aux != NULL && aux->valor != valor) {
            ant = aux; // Guarda o n� atual como "anterior"
            aux = aux->prox; // Avan�a para o pr�ximo n�
        }
        
        if(aux == NULL) { // Se o valor n�o foi encontrado
            printf("\nElemento nao encontrado para exclusao");
        } else {
            // Caso especial: se o n� a remover � o primeiro da lista
            if(ant == NULL) {
                removido = aux->valor;
                dados = aux->prox; // Muda o in�cio da lista para o pr�ximo n�
            } else { // Caso o n� a remover n�o seja o primeiro
                removido = aux->valor;
                ant->prox = aux->prox; // Desconecta o n� atual da lista
            }
            free(aux); // Libera a mem�ria usada pelo n� removido
            printf("\nElemento Removido: %i", removido);
        }
    }
    return dados; // Retorna o in�cio atualizado da lista
}

// Fun��o principal que exibe um menu de op��es
int main() {
    int op, remove;
    struct lista *dados = NULL;

    // Menu de op��es
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
                dados = insere(); // Chama a fun��o para inserir um novo valor
                break;
            case 2: 
                imprime(dados); // Chama a fun��o para imprimir todos os valores
                break;
            case 3:
                printf("\nEntre com valor para remover: ");
                scanf("%i", &remove); // L� o valor a ser removido
                dados = excluir(dados, remove); // Chama a fun��o para remover o valor
                break;
            case 4:
                exit(1); // Encerra o programa
        }
    }
}

