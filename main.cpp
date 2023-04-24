#include "sharkframe.h"
#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

int main(void) {
  FILE *file9;

  file9 = fopen("file9.csv", "w");

  if (file9 == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  struct t_array {
    const unsigned char *arr;
    int size;
  };

  vector<struct t_array> vtr = {

      {.arr = pkt8, .size = sizeof(pkt8)},
  };

  int biggestSize = 0;

  for (int i = 0; i < vtr.size(); i++) {
    if (vtr[i].size > biggestSize) {
      biggestSize = vtr[i].size;
    }
  }

  int loop = 0;

  while (1) {
    for (int i = 0; i < vtr.size(); i++) {
      if (loop < vtr[i].size) {
        fprintf(file9, "%d,", vtr[i].arr[loop]);
      }
    }

    if (++loop < biggestSize) {
      fprintf(file9, "\n");
    }

    else {
      break;
    }
  }

  fclose(file9);
  return 0;
}
