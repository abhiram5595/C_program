#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //printf("\nstring %s\n", s);
    //int i = 0;
    while(*s != '\0')
    {
        //i++;
        //printf("hello\n");
        if(*s == ' ')
        {
            printf("\n");
        }
        else if((*s == '\n') || (*s == '%'))
        {
            break;
        }
        else
        {
            printf("%c",*s);
        }
        s++;
    }

    //printf("\nnew line\n");
    return 0;
}