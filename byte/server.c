#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h> 
#include <time.h> 

int main(int argc, char *argv[]) {
    char arr[50];
    int fd = open("pipe", O_RDONLY);
    if (fd == -1){
        return 1;
    }
    for(int i=0; i<20; i++){
        if (read(fd, &arr[i], sizeof(char)) == -1){
            return 2;
        }
    }


    for(int j=1; j<strlen(arr); j++){
        if(arr[j+1]=='\0'){
            break;
        }
        if(arr[j]=='$'){
            continue;
        }
        printf("%c ", arr[j]);
    }

    close(fd);




}