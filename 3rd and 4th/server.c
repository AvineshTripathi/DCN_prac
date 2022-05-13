#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int arr[5];
    int fd = open("sum", O_RDONLY);
    if (fd == -1){
        return 1;
    }
    int i;
    for(i=0; i<5; i++){
        if (read(fd, &arr[i], sizeof(int)) == -1){
            return 2;
        }
        printf("recieved %d\n", arr[i]);
    }
    printf("done with 1 process\n");
    close(fd);
    // assignment 4 starts from here


    int new_arr[10];
    srand(time(NULL));

    int kd = open("sum", O_WRONLY);
    if(kd == -1){
        return 1;
    }
    for(int k=0; k<10 ; k++){
        new_arr[i]= rand() % 100;
    }

    for(int m=0; m<10; m++){
        if(write(fd, &new_arr[i], sizeof(int)) == -1){
            return 2;
        }
        printf("wrote %d\n", new_arr[m]);
    }

    close(kd);
    return 0;
}