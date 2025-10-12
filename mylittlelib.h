#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRadix(int num) { return floor(log10(num)) + 1; }

int getAnyNumberByIndex(int num, int index, int base) {
  int radix = getRadix(num) - 1;
  int indexRad = (int)(pow(10, radix - index));
  if (index > radix)
    return -1;
  return num / indexRad % base;
}

int getArraySize(int *array) { return sizeof(array) / sizeof(array[0]); }

void printArray(int *num, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    if (i == arraySize - 1)
      printf("%d\n", num[i]);
    else
      printf("%d - ", num[i]);
  }
  printf("\n");
}

int reverseInt(int num) {
  int radix = getRadix(num) - 1;
  for (int i = 0; i < radix; i++) {
  }
  return 0;
}

struct dTB {
  char *binary;
  int len;
};

struct dTB decimalToBinary(int *n) {
  struct dTB ret;
  char *res = (char *)malloc(32 + 1);
  if (res == NULL) {
    perror("Allocate memory error!");
    struct dTB error_ret = {NULL, 0};
    return error_ret;
  }

  int k = 0;
  int num = *n;
  while (num > 1) {
    res[k] = num % 2 + '0';
    num /= 2;
    k++;
    if (num == 1) {
      res[k] = 1 + '0';
      k++;
    }
  }
  res[k] = 0;

  char *trimmed = (char *)malloc(k + 1);
  memcpy(trimmed, res, k + 1);
  free(res);

  for (int i = 0; i < k / 2; i++) {
    char t = trimmed[i];
    trimmed[i] = trimmed[k - 1 - i];
    trimmed[k - 1 - i] = t;
  }
  ret.binary = trimmed;
  ret.len = k;
  return ret;
}

long long fastPow(int *num, int *extend) {
  struct dTB binaryExp = decimalToBinary(extend);
  int k = binaryExp.len;
  long long res = *num;
  printf("Res - %lld\n", res);
  for (int i = 1; i < k; i++) {
    if (binaryExp.binary[i] == '0') {
      res = res * res;
    } else {
      res = (res * res) * *num;
    }

    if (res > LLONG_MAX / res) {
      fprintf(stderr, "Overflow detected!\n");
      break;
    }
  }
  free(binaryExp.binary);
  return res;
}
