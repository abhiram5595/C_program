#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char *str;
    str = malloc(1024 * sizeof(char));
    scanf("%[^\n]",str);
    str = realloc(str, strlen(str)+1);
    
    // Read a line from user input
    //fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline (fgets includes it)
    //str[strcspn(str, "\n")] = '\0';
    
    printf("string %s\n", str);

    // Tokenize using space as delimiter
    char* token = strtok(str, " ");
    printf("%s line %d\n", token,__LINE__);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
        printf("%s line %d\n", token, __LINE__);
    }

    //Write your logic to print the tokens of the sentence here.
    return 0;
}