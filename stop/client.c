#include<stdio.h>
#include<sys/stat.h>12365
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int res,length,n;
char buff[100],buff1[100];
printf("enter the no. of data: ");
scanf("%d",&n);
res=open("myfifo",O_WRONLY);
write(res,n,sizeof(int));
for(int i=0;i<n;i++)
{
printf("\nenter the data: ");
scanf("%s",buff);
res=open("myfifo",O_WRONLY);
write(res,buff,100);
res=open("myfifo",O_RDONLY);
// printf("test");
read(res,buff1,100);
length=strlen(buff1);
printf("data is %s ", buff);
if(length != 0)
{
printf(" \nack is %s", buff1);
}
else
{
  printf("ack not received");
  break;
}
}
return 0;
}