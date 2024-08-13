#include <stdio.h>
#include <stdlib.h>

int main(){
    int Q, N;
    scanf("%d", &Q);
    scanf("%d", &N);

    int *pages = (int*)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++) scanf("%d", &pages[i]);

    int *frames = (int*)malloc(Q * sizeof(int));
    for(int i = 0; i < Q; i++) frames[i] = -1;

    int page_faults = 0;
    int next_frame = 0;

    for(int i = 0; i < N; i++){
        int found = 0;
        for(int j = 0; j < Q; j++){
            if(frames[j] == pages[i]){
                found = 1;
                break;
            }
        }

        if(!found){
            frames[next_frame] = pages[i];
            next_frame = (next_frame + 1) % Q;
            page_faults++;
        }
    }

    printf("%d\n", page_faults);
    free(pages);
    free(frames);
    return 0;
}