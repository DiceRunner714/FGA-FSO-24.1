#include <stdio.h>

typedef struct Process{
    int PID;
    int exec_time;
}Process;

int main(){
    int N, end = 0, finished = 0;
    int cycle_time, run_time = 0;
    scanf("%d", &N);
    Process list[N];
    scanf("%d", &cycle_time);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &list[i].PID, &list[i].exec_time);
        list[i].exec_time *= 1000;
    } 

    int beg = 0;
    while(1){
        for(int i = beg; i < N; i++){
            if(list[i].exec_time > 0){
                if(finished+1 == N){
                    printf("%d (%d)\n", list[i].PID, run_time+list[i].exec_time);
                    return 0;
                }
                else if(list[i].exec_time >= cycle_time){
                    list[i].exec_time -= cycle_time;
                    run_time += cycle_time;
                }else{
                    run_time += list[i].exec_time;
                    list[i].exec_time = 0;
                }
                if(list[i].exec_time == 0){
                    if(i == beg) beg++;
                    printf("%d (%d)\n", list[i].PID, run_time);
                    finished++;
                }
            } 
        }
    }
    return 0;
}