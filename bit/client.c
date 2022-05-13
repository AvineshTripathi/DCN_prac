#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int res, len, count=0;
    int i=0;
    int j=0;
    char buf[100];
    char buff2[100];

    res = mkfifo("myfifo", 0766);
    if (res)
    {
        printf("The pipe is created successfully\n");
    }

    res = open("myfifo", O_RDONLY);
    read(res, &buf, 100);

    len = strlen(&buf);

    printf("The code received is: %s\n", buf);

    for (int i = 8; i < len-9-1; i++)
    {
        if (buf[i] == '0')
        {
            count = 0;
        }
        else if (buf[i] == '1')
        {
            count++;
            if (count == 5)
            {
                count = 0;
                buff2[j] = buf[i];
                i+=2;
                j++;
            }
        }

        buff2[j] = buf[i];

        j++;
    }



    printf("The data is: %s\n", buff2);

}