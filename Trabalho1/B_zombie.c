#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int amountSU = 0;
__pid_t filho;

void handler(int signalID){
    int status;
    amountSU ++;
    if(amountSU == 1){
        filho = fork();
        if(filho == 0) exit(0);
    }else if(amountSU == 2){
        waitpid(filho, &status, 0);
    }else if(amountSU == 3) exit(0);
}

int main(){
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while(1){}
    return 0;
}