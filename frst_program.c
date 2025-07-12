#include <stdarg.h>
#include <stdio.h>

void my_scanf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    //printf("%s\n", format);

    for (const char* ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == '%') {
            ptr++; // Move to format specifier
            switch (*ptr) {
                case 'd': {
                    int *i = va_arg(args, int*);
                    //printf("value %d pointer %d\n", i, *i); // Print the value for demonstration
                    scanf("%d",i);
                    break;
                }
                case 's': {
                    char* str = va_arg(args, char*);
                    scanf("%s", str);
                    break;
                }
                default: {
                    // Handle unknown formats or just skip
                    break;
                }
            }
        }
    }

    va_end(args);
}

void my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while(*format) {
        if (*ptr == '%') {
            ptr++; // Move to format specifier
            switch (*ptr) {
                case 'd': {
                    int i = va_arg(args, int);
                    printf("%d", i);
                    break;
                }
                case 'c': {
                    char c = (char)va_arg(args, int); // char is promoted to int
                    putchar(c);
                    break;
                }
                case 's': {
                    char* s = va_arg(args, char*);
                    printf("%s", s);
                    break;
                }
                case 'a': {
                    // Custom format for demonstration, not standard
                    char* str1 = va_arg(args, char*);
                    char* str2 = va_arg(args, char*);
                    printf("%s%s", str1, str2);
                    break;
                }
                case '%': {
                    putchar('%');
                    break;
                }
                default: {
                    putchar('%');
                    putchar(*ptr); // Unknown format, print as-is
                    break;
                }
            }
        } else {
            putchar(*ptr);
        }
        format++;
    }

    va_end(args);
}

int main()
{
    int age;
    char initial;
    char name[50];
    my_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
    my_printf("Character: %c, Percent sign: %%\n", 'A');
    my_printf("Unknown format: %x\n", 42); // Will print as-is
    my_printf("hey %a format\n", "abhi" , "ram");
    printf("Enter your age, initial, and name:\n");

    my_scanf("%d %c %s", &age, &initial, name);

    printf("You entered: Age = %d, Initial = %c, Name = %s\n", age, initial, name);

    my_printf("End of program.\n");
    return 0;
}