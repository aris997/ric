#include <stdio.h>

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *bytes = (unsigned char*) ptr;
    unsigned char bit;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            bit = (bytes[i] >> j) & 1;
            printf("%u", bit);
        }
    }
    puts("");
}


int main(int argc, char **argv) {

    char * a = argv[1];
    printf("'%s' %ld\nPrintBits: ", a, sizeof(a));
    printBits(sizeof(a)/8, &a);

    return 0;
}

