#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {
        int *array;
        int shmid;
        int new = 1;
        char pathname[] = "for_ipc.ipc";
        key_t key;
        if((key = ftok(pathname, 0)) < 0) {
                printf("ne ydalos sgenerirovat klych\n");
                exit(-1);
        }
        if((shmid = shmget(key, 3*sizeof(int), 0666 | IPC_CREAT | IPC_EXCL)) < 0) {
                if (errno != EEXIST) {
                        printf("Ne ydalos cjzdat segment razdel pamyati\n");
                        exit(-1);
                }
                else {
                        if((shmid = shmget(key, 3*sizeof(int), 0)) < 0) {
                                printf("Ne ydalos naiti oblast razdel pamyati\n");
                                exit(-1);
                        }
                        new = 0;
                }
         }
         if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
                 printf("Ne ydalos pricoedinit segment k adr. prostranstvy tekychego prochessa\n");
                 exit(-1);
         }
         if (new) {
                 array[0] = 0;
                 array[1] = 1;
                 array[2] = 1;
         }
         else {
                 array[1] += 1;
                 array[2] += 1;
         }
         printf("Programa 1 zapyskalas %d raz(a), programma 2 - %d raz(a), vsego zapyskov - %d\n",  array[0], array[1], array[2]);
         if(shmdt(array) < 0) {
                 printf("Ne ydalos ickluchit segment iz adresnogo prostranstva tekychego prosessa\n");
                 exit(-1);
         }
        return 0;
}

