#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        int semid;
        char pathname[] = "for_ipc.ipc";
        key_t key;
        struct sembuf mybuf;
        if((key = ftok(pathname,0)) < 0) {
                printf("Ne ydalos cgenerirovat klych ipc\n");
                exit(-1);
        }
        if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
            printf("Ne ydalos polychit deckriptor macciva cemaforov\n");
            exit(-1);
        }
        mybuf.sem_op = -1;
        mybuf.sem_flg = 0;
        mybuf.sem_num = 0;
        printf("Ogidanie razblok tekychego prosessa\n");
        if(semop(semid, &mybuf, 1) < 0) {
                printf("ne ydalos vipolniot operachiy nad semaforom\n");
                exit(-1);
        }
        printf("Tekychiy prochess razblokirovan\n");
        return 0;
}




