#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINE_LEN 15
#define LINES 1000
int main(int argc, char const *argv[])
{
    int res = 0;
    int a1, b1, a2, b2;
    char cadena[LINE_LEN];
    char datos[LINES][LINE_LEN];
    int idx = 0;

    FILE *fichero = fopen("day4.txt", "r");
    if (!fichero)
    {
        printf("ERROR");
        return 1;
    }
    while (fgets(cadena, LINE_LEN, fichero))
    {
        memcpy(datos[idx], cadena, LINE_LEN);
        idx++;
    }
    fclose(fichero);
    for (int i = 0; i < LINES; i++)
    {
        sscanf(datos[i], "%d-%d, %d-%d", &a1, &b1, &a2, &b2);
        //if(a1 <= a2 && b1 >= b2 || a2 <= a1 && b2 >= b1){
            //res += 1;
        //}
        for (int i=a1; i <= b1; i++)
        {
            if (i >= a2 && i <= b2)
            {
                res += 1;
                break;
            }  
        }
    }
    printf("%d", res);
    return 0;
}
