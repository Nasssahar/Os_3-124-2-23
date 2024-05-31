#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        int semid; //IPC-deckriptor dla massiva semafora
        char pathname[] = "for_ipc.ipc"; //Imy faila, c pomochyu kotorogo generiryency ipc-klych
        key_t key; //Peremena dla xranenia ipc-klycha 
        struct sembuf mybuf; //Stryktyra dannix, zadaychya operachii nad opredelennim  semaforom
        //prochess generachii ipc-klycha
        if((key = ftok(pathname,0)) < 0) {
                printf("Ne ydalos cgenerirovat klych ipc\n");
                exit(-1);
        }
        //Prochess polychenia doctypa k massivy semaforov dla konkretnogo ipc-kltcha
        //Ecli massiva  semaforov ne sychectvyet, to pitaemsy ego sozdat
        if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
            printf("Ne ydalos polychit deckriptor macciva cemaforov\n");
            exit(-1);
        }
        mybuf.sem_op = -1; //Kodirovanie operchii D(semid1,1)
        mybuf.sem_flg = 0;
        mybuf.sem_num = 0;
        //Operachii bydyt ocychestvlztcy nad semaforom 0, kod operachii -1
        printf("Ogidanie razblok tekychego prosessa\n");
        //Vipolnyem operachi nad semaforom
        if(semop(semid, &mybuf, 1) < 0) {
                printf("ne ydalos vipolniot operachiy nad semaforom\n");
                exit(-1);
        }
        printf("Tekychiy prochess razblokirovan\n");
        return 0;
}




