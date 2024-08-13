#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int status;
    char command[255], argument[255];
    double time, ttime;
    struct timeval start;
    struct timeval finish;
    while(scanf("%s %s", command, argument) != EOF){
        gettimeofday(&start, NULL);
        __pid_t process = fork();
        if(process == 0){
            execl(command, command, argument, NULL);
            printf("> Erro: %s\n", strerror(errno));
            fflush(stdout);
            fclose(stdin);
            exit(errno);
        }
        wait(&status);
        gettimeofday(&finish, NULL);
        time = finish.tv_sec - start.tv_sec + (finish.tv_usec - start.tv_usec)/1000000.0;
        ttime += time;
        printf("> Demorou %.1lf segundos, retornou %d\n", time, WEXITSTATUS(status));
        fflush(stdout);
    }
    printf(">> O tempo total foi de %.1lf segundos\n", ttime);
    fflush(stdout);
    return 0;
}