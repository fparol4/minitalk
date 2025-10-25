#include <stdio.h>
int main(int argc, char *argv[])
{
    char *f = "1110010";
    int b = (0b0 * 10) + 1;

    b = 0b0 << 1;

    printf("%d", b);
	return 0;
}
