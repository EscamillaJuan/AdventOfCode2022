#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 5
#define LINES 2500


int main()
{
    int total_score = 0, rock = 1, paper = 2, scissors = 3, win = 6, draw = 3;
    int idx = 0;
    char *item;
    char lines[LINES][LINE_LENGTH];
    char buffer[LINE_LENGTH];
    FILE *fichero = fopen("dataDay2.txt", "r");
    if (fichero == NULL)
    {
        printf("No se puede abrir el fichero");
        return 1;
    }
    while (fgets(buffer, LINE_LENGTH, fichero))
    {
        strtok(buffer, "\n");
        memcpy(lines[idx], buffer, LINE_LENGTH);
        idx++;
    }
    fclose(fichero);
    for(int i=0; i<LINES; i++){
        if(strcmp(lines[i], "A Y")==0){
            total_score += draw + rock;
        }
        if(strcmp(lines[i], "A X")==0){
            total_score += scissors;

        }
        if(strcmp(lines[i], "A Z")==0){
            total_score += win + paper;
        }
        if(strcmp(lines[i], "B Y")==0){
            total_score += draw + paper;
        }
        if(strcmp(lines[i], "B X")==0){
            total_score += rock;
        }
        if(strcmp(lines[i], "B Z")==0){
            total_score += win + scissors;
        }
        if(strcmp(lines[i], "C Y")==0){
            total_score += draw + scissors;
        }
        if(strcmp(lines[i], "C X")==0){
            total_score +=  paper;
        }
        if(strcmp(lines[i], "C Z")==0){
            total_score += win + rock;
        }
    }
    printf("%i", total_score);
    return 0;
}