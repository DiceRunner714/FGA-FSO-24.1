#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int *instrucoes;
    int tamanho;
    int atual;
} Processo;

int compareByFinTime(const void *a, const void *b) { return ((int *)a)[1] - ((int *)b)[1]; }

int main(){
    int N, tempo = 0;
    scanf("%d", &N);
    int m[N];
    int *q[N];
    int tamanho_fila = 0;
    int tempoConclusao[N][2];
    for(int i = 0; i < N; ++i) scanf("%d", &m[i]);
    for(int i = 0; i < N; ++i){
        Processo *p = (Processo*)malloc(sizeof(Processo));
        p->id = i + 1;
        p->tamanho = m[i];
        p->instrucoes = (int*)malloc(m[i]*sizeof(int));
        p->atual = 0;
        for(int j = 0; j < m[i]; ++j) scanf("%d", &p->instrucoes[j]);
        q[tamanho_fila++] = (int*)p;
    }
    while(tamanho_fila > 0){
        Processo *atual = (Processo *)q[0];
        for(int i = 0; i < tamanho_fila - 1; ++i) q[i] = q[i+1];
        --tamanho_fila;
        while(atual->atual < atual->tamanho){
            if(atual->instrucoes[atual->atual] == 0){
                tempo += 10;
                ++atual->atual;
            }
            else{
                atual->instrucoes[atual->atual] = 0;
                q[tamanho_fila++] = (int*)atual;
                break;
            }
        }
        if(atual->atual == atual->tamanho){
            tempoConclusao[atual->id - 1][0] = atual->id;
            tempoConclusao[atual->id - 1][1] = tempo;
        }
    }
    qsort(tempoConclusao, N, 2 * sizeof(int), compareByFinTime);

    for(int i = 0; i < N; ++i) printf("%d (%d)\n", tempoConclusao[i][0], tempoConclusao[i][1]);
    return 0;
}
