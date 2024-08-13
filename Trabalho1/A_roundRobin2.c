#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int tempo_total;
    int tempo_exec;
} Process;

int pronto(Process);
int tempo_excedido(Process);

typedef struct Node {
    Process processo;
    struct Node *prox;
} Node;

Node *init_list();
int vazia(Node *);
void insere(Node *, Process);

int main(void)
{
    int N, T;

    scanf("%d %d", &N, &T);
    
    Node *tail = init_list();

    for (int i = 0; i < N; i++)
    {
        Process p;
        scanf("%d %d", &p.pid, &p.tempo_total);
        p.tempo_total *= 1000;
        p.tempo_exec = 0;

        insere(tail, p);
    }

    Node *prev = tail->prox;
    Node *curr;
    int time = 0;
    
    while (!vazia(tail))
    {
        curr = prev->prox;
        curr->processo.tempo_exec += T;
        time += T;

        if (pronto(curr->processo)) {
            time -= tempo_excedido(curr->processo);
            
            printf("%d (%d)\n", curr->processo.pid, time);

            Node *prox = curr->prox;

            if (prox == curr)
                tail->prox = NULL;
            else
                prev->prox = prox;

            free(curr);
        }
        else
            prev = curr;   
    }

    free(tail);
    return 0;
}

// Verifica se um processo está pronto
int pronto(Process p)
{
    return p.tempo_exec >= p.tempo_total;
}

int tempo_excedido(Process p)
{
    return p.tempo_total - p.tempo_exec;
}

// Inicializa a lista encadeada
Node *init_list()
{
    Node *list = malloc(sizeof(Node));
    list->prox = NULL;
    return list;
}

// Verifica se a lista está vazia
int vazia(Node *tail)
{
    return tail->prox == NULL;
}

// Insere no final da lista
void insere(Node *tail, Process p)
{
    Node *novo = malloc(sizeof(Node));
    novo->processo = p;

    if (vazia(tail)) {
        /* Se a lista estiver vazia, o nó inserido deve apontar para ele mesmo */
        novo->prox = novo; 
    }
    else {
        novo->prox = tail->prox->prox;
        tail->prox->prox = novo;
    }

    tail->prox = novo;
}