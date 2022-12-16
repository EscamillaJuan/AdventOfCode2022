#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 100
#define LINES 6

int main(int argc, char const *argv[])
{
    char priority;
    int idx = 0, value = 0, total = 0;
    size_t len = 0;
    size_t halflen = 0;
    char lines[LINES][LINE_LENGTH];
    char buffer[LINE_LENGTH];
    FILE *fichero = fopen("data_day3.txt", "r");
    if (fichero == NULL)
    {
        printf("ERROR");
    }
    while (fgets(buffer, LINE_LENGTH, fichero))
    {
        memcpy(lines[idx], buffer, LINE_LENGTH);
        idx++;
    }
    for (int i = 0; i < LINES; i++)
    {   
        len = strlen(lines[i]) - 1;
        halflen = len / 2;
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                if (lines[i][j] == lines[i][k+halflen])
                {
                    printf("%c", lines[i][j]);
                    priority = lines[i][j];
                    goto flag;
                }
            }
        }
    flag:
        if (priority >= 'a' && priority <= 'z')
        {
            value = priority - 'a' + 1;
        }
        if (priority >= 'A' && priority <= 'Z')
        {
            value = priority - 'A' + 27;
        }
        total += value;
    }
    printf("%i", total);
    return 0;
}
