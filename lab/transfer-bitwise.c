#include <stdio.h>

void T0_TRANSFER_INT(void) {

  int k;
  int c_bit = 0b011;

  for (int i = 3; i > 0; --i) {
    int lb = c_bit & 0x1;
    c_bit >>= 1;
    k += lb << (3 - i);
    printf("x0:%d\n", lb);
  }
  printf("K:%d\n", k);
}

void T1_TRANSFER_STR(void) {
  int k = 0;
  char *c_byte = "011";

  for (int i = 0; i < 3; ++i) {
    k = (k << 1) | c_byte[i] - '0';
  }
  printf("K:%d\n", k);
}

int main(int argc, char *argv[]) {
  T1_TRANSFER_STR();
  return 0;
}
