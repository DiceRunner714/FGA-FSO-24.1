#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef struct{
    int page;
    int time;
} Frame;

int findLRU(Frame frames[], int n){
    int i, minimum = frames[0].time, pos = 0;
    for(i = 1; i < n; ++i){
        if(frames[i].time < minimum){
            minimum = frames[i].time;
            pos = i;
        }
    }
    return pos;
}

int main(){
    int Q, N;
    scanf("%d", &Q);
    scanf("%d", &N);

    int *pages = (int*)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++) scanf("%d", &pages[i]);

    Frame *frames = (Frame *)malloc(Q * sizeof(Frame));
    for (int i = 0; i < Q; i++) {
        frames[i].page = -1;
        frames[i].time = 0;
    }

    int page_faults = 0;
    int counter = 0;

    for(int i = 0; i < N; i++){
        int found = false;
        for(int j = 0; j < Q; j++){
            if(frames[j].page == pages[i]){
                found = true;
                frames[j].time = ++counter;
                break;
            }
        }

        if(!found){
            int pos = findLRU(frames, Q);
            frames[pos].page = pages[i];
            frames[pos].time = ++counter;
            page_faults++;
        }
    }

    printf("%d\n", page_faults);
    free(pages);
    free(frames);
    return 0;
}