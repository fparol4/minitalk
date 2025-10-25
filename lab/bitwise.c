#include <stdio.h>

int ft_binary(int n) {
    if (n == 0)
        return printf("0");
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    return 0;
}

// left shift "<<" | MULTIPLICACAO
// => N x 2 ^ M
// => 10 << 1 = 10 * (2 ** 1)
// => 25 << 5 = 25 * (2 ** 5)
void t_leftshift()
{
    int x0 = 10 << 1;
    int x1 = 25 << 5;
    int x2 = 10 << 3;
    printf("%d;%d;%d;\n", x0, x1, x2);
}

// right shift ">>" | DIVISAO
// => N / (2 ^ M)
// => 10 >> 2 = 10 / (2 ** 2) = 10 / 4 = 2.5 (floor) = 2
// => 32 >> 4 = 32 / (2 ** 4) = 32 / 16 = 2
void    t_rightshift()
{
    int x0 = 10 >> 2;
    int x1 = 24 >> 2;
    printf("%d;%d;\n", x0, x1);
}

int main()
{
    t_leftshift();
    t_rightshift();
}
