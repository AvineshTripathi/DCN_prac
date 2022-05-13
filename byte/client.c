 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>x

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h> 
#include <time.h> 

int main(int argc, char *argv[]) {
    char arr[50], temp[50];
    int n=0;
    printf("enter the code: ");
    gets(arr);
    for(int i=0; i<strlen(arr); i++){
        if(arr[i]=='#'){
            temp[n]='$';
            temp[n+1]='#';
            n=n+2;
        }else {
            temp[n]=arr[i];
            n++;
        }
    }
    char point[n+2];
    point[0]='#';
    point[n+1]='#';
    for(int m=1; m<n+1; m++){
        point[m]=temp[m-1];
    }

    int fd = open("pipe", O_WRONLY);
    if(fd == -1){
        return 1;
    }

    for(int j=0; j<n+2; j++){
        if(write(fd, &point[j], sizeof(char)) == -1){
            return 2;
        }
        printf("%c ", point[j]);
    }

    close(fd);


}