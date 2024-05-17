#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main() {
        int fd[2], result;
        size_t size;
        char string[] = "Hello from pipe!\n";
        char resstring[17];
        result = fork();
         if (pipe(fd)<0) {
                 printf("Ne ydalos sozdat pipe\n");
                 exit(-1);
        }
        if (result < 0) {
                printf("Ochibka pri zapuske  fork()\n");
                exit(-1);
        }
        else if (result > 0) {
                if(close(fd[0]<0) {
                        printf("Ne ydalos zakrit pipe dla chtenia\n");
                        exit(-1);
        }

        if (pipe(fd)<0) {
                 printf("Ne ydalos sozdat pipe\n");
                 exit(-1);
        }
        size = write(fd[1], string, 17);
        if (size != 17) {
                 printf("Ne ydalos zapisat 17 bait iz stroki\n");
                 exit(-1);
        }
        size = read(fd[0], resstring, 17);
        if (size != 17) {
                 printf("Ne ydalos prochitat 17 bait iz pipe\n");
                 exit(-1);
        }
        printf("Prochitannaya stroka: %s\n", resstring);
        if (close(fd[0])<0) {
                printf("Ne ydalos zakrit pipe dla chtenia\n");
                exit(-1);
        }
        if(close(fd[1])<0) {
                printf("Ne ydalos zakrit pipe dla zapisi\n");
                exit(-1);
        }
        return 0;
}
