#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

 int main() {
  int i,j,divlen,datal,res;
  char buf[100], div[30],temp[30],quot[100],rem[100],div1[30];
  printf("Enter buf: ");
  scanf("%s",buf);
  printf("Enter div: ");
  scanf("%s",div);
  divlen=strlen(div);
  datal=strlen(buf);
  strcpy(div1,div);
  for (i=0;i<divlen-1;i++) {
    buf[datal+i]='0';
  }
  printf("\n%s :buf data after inserting 0",buf);
  for (i=0;i<divlen;i++)
   temp[i]=buf[i];
  for (i=0;i<datal;i++) {
    quot[i]=temp[0];
    if(quot[i]=='0')
     for (j=0;j<divlen;j++)
     div[j]='0'; else
     for (j=0;j<divlen;j++)
     div[j]=div1[j];
    for (j=divlen-1;j>0;j--) {
      if(temp[j]==div[j])
       rem[j-1]='0'; else
       rem[j-1]='1';
    }
    rem[divlen-1]=buf[i+divlen];
    strcpy(temp,rem);
  }
  strcpy(rem,temp);
  printf("\nQuotient is ");
  for (i=0;i<datal;i++)
   printf("%c",quot[i]);
  printf("\nRemainder is ");
  for (i=0;i<divlen-1;i++)
   printf("%c",rem[i]);
  printf("\nFinal buf is: ");
  for (i=0;i<datal;i++)
  {
    buf[i+datal]=rem[i];
  }
  printf("%s",buf);
  res = open("myfifo", O_WRONLY);
    write(res, buf, 100);
//   res = open("myfifo", O_WRONLY);
//     write(res, &rem, 100);
  res = open("myfifo", O_WRONLY);
    write(res, div1, 30);
  return 0;
}