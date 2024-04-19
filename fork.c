#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main() { 
           pid_t procid, parentid, result;
           int  a=0;
           result = fork();
           if(result<0) {
                   printf("Ошибка при выполнении fork()\n");
                   exit(-1);
           }
           else if(result==00) {
                   a=a=1;
                   procid = getpid();
                   parentid = getppid();
                   printf("Ид. текущего процесса: %d\n", procid);
                   printf("Ид. родительского процесса: %d\n", parentid);
                   printf("значение переменной a:%d\n", a);
           }
           else {
                   a=a+1;
                   procid = getpid();
                   parentid = getppid();
                   printf("Ид. текущего процесса: %d\n", procid);
                   printf("Ид. родительского процесса: %d\n", parentid);
                   printf("значение переменной a:%d\n", a);
                   printf("значение переменной result: %d\n", result);
           }
           return 0;
} 
