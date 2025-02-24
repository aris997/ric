#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv) {
    char path[1035];

    /* Open the command for reading. */
    FILE *fp = popen("shuf -i 0-1000000000 -n 1", "r");
    // FILE *fp = popen("whoami", "r");
    if (fp == NULL) {
      printf("Failed to run command\n" );
      exit(1);
    }

    // /* Read the output a line at a time - output it. */
    // while (fgets(path, sizeof(path), fp) != NULL) {
    //   printf("'%s'", path);
    // }

    /* close */


    // const int rand_seed = (int) *fgets(path, sizeof(path), fp);
    char * rand_seed = fgets(path, sizeof(path), fp);
    printf("rand seed: %s", rand_seed);
    pclose(fp);

    return 0;
}

//
// Created by rivar on 15/01/25.
//
