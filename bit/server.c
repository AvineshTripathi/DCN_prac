#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int res, len;
    int j = 0;
    int i = 0;
    int count = 0;

    char buf[100];
    char buff2[100];
    int flag_bit_count = 0;

    printf("Enter the string: \n");
    scanf("%s", &buf);
    len = strlen(buf);
    buff2[j] = '0';
    j++;
    while (j < 7)
    {
        buff2[j] = '1';
        j++;
    }

    buff2[j] = '0';
    j++;

    while (i < len)
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
                j++;
                i++;
                buff2[j] = '0';
                j++;
            }
        }

        buff2[j] = buf[i];
        i++;
        j++;
    }

    buff2[j] = '0';
    j++;
    while (flag_bit_count < 7)
    {
        buff2[j] = '1';
        j++;
        flag_bit_count++;
    }
    buff2[j] = '0';

    printf("The encrypted data is: %s\n", buff2);

    res = open("myfifo", O_WRONLY);
    write(res, &buff2, 100);

    return 0;

}