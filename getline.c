#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * custom_getline - to define the code
 * @lineptr: line code
 * @n: number 
 * @stream: code 
 * Return -1
 **/
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) 
{
    size_t pos = 0;
    int ch;

    if (*lineptr == NULL || *n == 0) {
        *n = 128;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    while ((ch = fgetc(stream)) != EOF && ch != '\n') {
        (*lineptr)[pos++] = ch;

        if (pos >= *n) {
            *n *= 2;
            *lineptr = (char *)realloc(*lineptr, *n);
            if (*lineptr == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }

    if (pos > 0 || ch != EOF) {
        (*lineptr)[pos] = '\0';
        return pos;
    }

    return -1; 
}
