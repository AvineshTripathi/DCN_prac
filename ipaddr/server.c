#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int res,length,count;
char buff[100];
res=mkfifo("myfifo",0766);
if(res==0)
{
printf("\nMyfifo is created\n");
}
res=open("myfifo",O_RDONLY);
read(res,buff,100);
length=strlen(buff);
printf("The data is %s\n",buff);
count=0;
for(int m=0;m<length;m++)
{
  if(buff[m]=='.')
  {
    break;
  }
  else
  {
    count++;
  }
}
printf("test");
if(count==1)
{
  printf("\nit belongs to class a");
}
if(count==2)
{
  printf("\nit belongs to class b");
}
if(count==3)
{
  printf("\nit belongs to class c");
}

//res=open("myfifo",O_WRONLY);
//write(res,&length,sizeof(int));
return 0;
}