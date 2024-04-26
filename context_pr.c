#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[]) {
        pid_t procid, parentid, result;
        printf("Порождаем вечерний процесс\n");
        result = fork();
        if(result<0) {
                printf("ошибка при выполнении fork()\n");
                exit(-1);
        }
        else if(result==0) {
                procid = getpid();
                parentid = getppid();
                printf("Ид. текущего процесса: %d\n", procid);
                printf("Ид. родительского процесса: %d\n", parentid);
                printf("значение переменной result: %d\n", result);
                execle("./args.out", "./args.out", "args.c", 0, envp);
                printf("ошибка при выполнении системного вызова exec()\n");
                exit(-1);
        }
        else {
                 procid = getpid();
                 parentid = getppid();
                 printf("Ид. текущего процесса: %d\n", procid);
                 printf("Ид. родительского процесса: %d\n", parentid);
                 printf("значение переменной result: %d\n", result);
       }
       return 0;
}
