
#include "minitalk.h"

void panic(char *msg)
{
    printf("%s\n", msg);
    exit(1);
}

int ft_getpid()
{
  int pid;
  pid = getpid();
  return (pid);
}

char **ft_str_tobuffer(char *str)
{
    int len = ft_strlen(str);
    char **buffer = ft_calloc((len * 8) + 1, sizeof(char));
    for (int i = 0; i <= len; i++)
    {
        char *c_bin = ft_itoab(str[i], "01");
        c_bin = ft_padstart(c_bin, BYTE_SIZE, '0');
        printf("D0:%s\n", c_bin);
        buffer[i] = c_bin;
    }
    return buffer;
}
