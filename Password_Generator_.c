#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

int main() 
{
    int length, i;
    char password[MAX_LENGTH + 1]; // Fixed the array declaration
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
    srand(time(NULL));

    printf("Enter the length of the password: ");
    scanf("%d", &length);

    printf("Enter the complexity of the password you want to generate(1-4):\n");
    printf("1. Lowercase letters only.\n");
    printf("2. Lowercase and uppercase letters.\n");
    printf("3. Lowercase letters, uppercase letters, and numbers.\n");
    printf("4. Lowercase letters, uppercase letters, numbers, and symbols.\n");
    printf("---------------------------------------------------------------\n");
    int complexity;
    scanf("%d", &complexity);
    printf("---------------------------------------------------------------\n");

    if (complexity < 1 || complexity > 4) 
    {
        printf("Invalid complexity level.\n");
        return 1;
    }

    char* charset;
    int charset_length;
    switch (complexity) 
    {
        case 1:
            charset = lowercase;
            charset_length = strlen(lowercase);
            break;
        case 2:
            strcpy(password, lowercase);
            strcat(password, uppercase);
            charset = password;
            charset_length = strlen(password);
            break;
        case 3:
            strcpy(password, lowercase);
            strcat(password, uppercase);
            strcat(password, numbers);
            charset = password;
            charset_length = strlen(password);
            break;
        case 4:
            strcpy(password, lowercase);
            strcat(password, uppercase);
            strcat(password, numbers);
            strcat(password, symbols);
            charset = password;
            charset_length = strlen(password);
            break;
    }

    for (i = 0; i < length; i++) 
    {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0'; // add null terminator

    printf("The Generated password is: %s\n", password);

    return 0;
}
