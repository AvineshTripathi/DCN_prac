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
    srand(time(NULL));
    int i;
    for(i=0; i<5; i++){
        arr[i]= rand() % 100;
    }


    int fd = open("sum", O_WRONLY);
    if(fd == -1){
        return 1;
    }

    for(int j=0; j<5; j++){
        if(write(fd, &arr[i], sizeof(int)) == -1){
            return 2;
        }
        printf("wrote %d\n", arr[i]);
    }

    close(fd);

    //assignment 4


    int new_arr[10];
    int kd = open("sum", O_RDONLY);
    if (fd == -1){
        return 1;
    }
    int s;
    for(s=0; s<10; s++){
        if (read(kd, &new_arr[s], sizeof(int)) == -1){
            return 2;
        }
        printf("recieved %d", new_arr[s]);
    }
    printf("done with 2 process");
    close(kd);
   return 0; 
}