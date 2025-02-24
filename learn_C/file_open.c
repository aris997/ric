#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("File name: %s\n", argv[1]);
  FILE *file_input = fopen(argv[1], "r");
  if (file_input == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
//  fscanf(file_input, "%s\n", &line);

  read = getline(&line, &len, file_input);
  printf("%s\n", line);


  fclose(file_input);
}

//
// Created by rivar on 10/02/25.
//
