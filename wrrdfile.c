#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main() {
        int fd;
        size_t size;
        char string[] = "Gr.3.124.2.23";
        if ((fd = open("wrfile.txt", O_WRONLY|O_CREAT, 0666))<0) {
                printf(" Ne ydalos otkrit fail na zapis\n");
                exit(-1);
        }
        size = write(fd, string, 14);
        if (size != 14) {
                 printf("Ne ydalos zapisat v fail strokt iz 14 bait\n");
                 exit(-1);
        }
        ptint("stroka zapisana v fail wrfile.txt\n");
        if (close(fd) < 0) {
                printf ("ne ydalos zakrit fail\n");
                exit(-1);
        }
        return 0;
}
