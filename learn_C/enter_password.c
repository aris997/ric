#include <stdio.h>

int main() {
    char password[] = "password";

    char input_pw[32];

    printf("Insert password: ");
    scanf(input_pw, "%c\n");

    if (password == input_pw) {
        printf("Welcome!\n");
    } else {
        printf("Wrong password\n");
    }

    return 0;
}