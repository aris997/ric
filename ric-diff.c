#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("File names: \t %s\t %s\n", argv[1], argv[2]);
  FILE *file_left = fopen(argv[1], "r");
  FILE *file_right = fopen(argv[2], "r");
  if (file_left == NULL || file_right == NULL) {
    printf("Error opening left or right file %s\t %s\n", argv[1], argv[2]);
    return 1;
  }
  char *line_l = NULL;
  char *line_r = NULL;
  ssize_t len_l;
  ssize_t len_r;
  size_t buff_l;
  size_t buff_r;
  unsigned int len = 0;

  len_l = getline(&line_l, &buff_l, file_left);
  len_r = getline(&line_r, &buff_r, file_right);
  printf("Files stats: \t len %zu \t len %zu\n", len_l, len_r);
  for (int i = 0; i < len_l; i++) {
    printf("%c", line_l[i]);
  }
  printf("\n");
  if (len_l > len_r) {
    len = (unsigned int) len_l;
  } else {
    len = (unsigned int) len_r;
  }
  for (size_t i = 0; i < len; i++) {
    if (line_l[i] == line_r[i]) {
      printf("=");
    } else {
      printf("\033[32m+\033[0m");
    }
  }
  printf("\n");
  for (int i = 0; i < len_r; i++) {
    printf("%c", line_r[i]);
  }
  printf("\n");
  fclose(file_left);
  fclose(file_right);
}

//
// Created by rivar on 10/02/25.
//
