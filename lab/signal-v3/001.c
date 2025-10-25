#include "../../lib/libft.h"
#include "../../lib/ft_printf.h"

char *str_buffer(char *str)
{
    int byte_size = 8;
    int len = ft_strlen(str);
    char *buffer = calloc(len * byte_size, sizeof(char));

    int i = 0;
    while (str[i]) {
        int c_number = str[i];
        char *c_binary = ft_itoa(c_number, "01");
        printf("D0:%s\n", c_binary);
        ft_memcpy(buffer + (i * byte_size), c_binary, ft_strlen(c_binary));
        ++i;
    }

    printf("b0: %s", buffer);
    return buffer;
}

int main(int argc, char *argv[]) {
    char *m = "Hi, i'm a really good programmer";
    str_buffer(m);
}
