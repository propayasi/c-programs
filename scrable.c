#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNITY 1
#define LEN_MAX 100

void scoring_func(const char *string);
void string_uppercase(char *string);
int check_space(const char *string);

int main()
{
    char string[LEN_MAX];
    printf("Please enter the string: ");
    fgets(string, LEN_MAX, stdin);

    int has_space = check_space(string);
    if (has_space)
    {
        printf("Illegal input\n");
        return 1;
    }

    string_uppercase(string);
    scoring_func(string);

    return 0;
}

void scoring_func(const char *string)
{
    int length = strlen(string);
    int score = 0;
    for (int index = 0; index < length; index++)
    {
        switch (toupper(string[index]))
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                score += UNITY;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J':
            case 'X':
                score += 8;
                break;
            case 'Q':
            case 'Z':
                score += 10;
                break;
        }
    }
    printf("Your Scrabble score is: %d\n", score);
}

void string_uppercase(char *string)
{
    int length = strlen(string);
    for (int index = 0; index < length; index++)
    {
        string[index] = toupper(string[index]);
    }
}

int check_space(const char *string)
{
    int length = strlen(string);
    for (int index = 0; index < length; index++)
    {
        if (isspace(string[index]))
        {
            return UNITY;
        }
    }
    return 0;
}