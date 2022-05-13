#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int res,length,n;
char buff[100],buff1[100];
res=mkfifo("myfifo",0766);
if(res==0)
{
printf("\nMyfifo is created\n");
}
res=open("myfifo",O_RDONLY);
read(res,n,sizeof(int));
  printf("n is %d",&n);
for(int i=0;i<n;i++)
{
res=open("myfifo",O_RDONLY);
read(res,buff,100);
length=strlen(buff);
//printf("length%d",length);
if(length == 0)
{
  printf("\nthere is no data");
}
else
{
  printf("The data is %s\n",buff);
  printf("enter ack\n");
  scanf("%s",buff1);
  res=open("myfifo",O_WRONLY);
  write(res,buff1,100);
}
}
res=open("myfifo",O_WRONLY);
//write(res,&length,sizeof(int));
return 0;
}
