#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000000  // Maximum length of input string

// Simple string hash function (similar to Python's hash)
unsigned long hash_string(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// Function to read file content into a string
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Allocate memory for the string
    char* content = (char*)malloc(MAX_STRING_LENGTH);
    if (content == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        exit(1);
    }

    // Read the file
    size_t bytes_read = fread(content, 1, MAX_STRING_LENGTH - 1, file);
    content[bytes_read] = '\0';  // Null terminate the string

    fclose(file);
    return content;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    // Read strings from files
    char* st = read_file(argv[1]);
    char* st2 = read_file(argv[2]);
    
    clock_t start_time, end_time;
    double time_taken;
    long long cycles = 100000000LL;  // 1_000_000_00 in Python
    long long counter = 0;
    
    // Direct string comparison
    start_time = clock();
    for (long long i = 0; i < cycles; i++) {
        if (strcmp(st, st2) == 0) {
            // counter++;
        }
    }
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("execution time no hash: %.4f\n", time_taken);
    
    // Hash comparison
    start_time = clock();
    for (long long i = 0; i < cycles; i++) {
        if (hash_string(st) == hash_string(st2)) {
            // counter++;
        }
    }
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("execution time with hash: %.4f\n", time_taken);
    
    // Clean up
    free(st);
    free(st2);
    
    return 0;
}