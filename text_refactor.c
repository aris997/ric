#include <stdio.h>


char* cut_long_lines(char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("No file with name %s found.\n", file_name);
        return 1;
    }
    
}

int main(int argc, char **argv) {
    return 0;
}