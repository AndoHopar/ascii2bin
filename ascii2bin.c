#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {
int offset = 0x30;
int number = 0;
int retval = 1;
int digit;
int max = 4294967296;
byte ascii_value;

retval = read(STDIN_FILENO, &ascii_value, 1);
while (retval == 1 || ascii_value != '\n') {
    if ((ascii_value != '0') && (ascii_value != '1')) {
        return 1;

    } else {
        digit = ascii_value - offset;
        number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);
    }
 }
if (number > max) {
    fprintf(stderr, "Error Detected!\n");
    return 1;
 } else {
    printf("%u\n", number);
    return 0;
}
}
