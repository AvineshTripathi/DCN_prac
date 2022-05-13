#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int res,length;
char buff[100];
printf("enter the data: ");
scanf("%s",buff);
res=open("myfifo",O_WRONLY);
write(res,buff,100);
return 0;
}