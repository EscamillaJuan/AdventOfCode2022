#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 100
#define LINES 300

int main(int argc, char const *argv[])
{
    char priority, a, b, c;
    int idx = 0, value = 0, total = 0;
    size_t len = 0, len2 = 0, len3 = 0;
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
    for (int i = 0; i < LINES; i += 3)
    {
        len = strlen(lines[i]);
        len2 = strlen(lines[i + 1]);
        len3 = strlen(lines[i + 2]);
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len2; k++)
            {
                a = lines[i][j];
                b = lines[i + 1][k];
                c = lines[i + 2][k];
                if (lines[i][j] == lines[i + 1][k])
                {
                    for (int l = 0; l < len3; l++)
                    {
                        if (lines[i][j] == lines[i + 2][l])
                        {
                            // printf("%c", lines[i][j]);
                            priority = lines[i][j];
                            goto flag;
                        }
                    }
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

    /*for (int i = 0; i < LINES; i++)
    {
        len = strlen(lines[i]) - 1;
        halflen = len / 2;
        for (int j = 0; j < halflen; j++)
        {
            for (int k = 0; k < halflen; k++)
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
    }*/
    printf("%i", total);
    return 0;
}
