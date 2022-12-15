#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ELEMENTS_IN_LINE 10
#define ELEMENTS 2269

int main(){
    char cadena[ELEMENTS_IN_LINE];
    int datoExtraido[ELEMENTS];
    int idx = 0, val_sum = 0, max_val_sum = 0, max_val_sum2 = 0, max_val_sum3 = 0;
    FILE *fichero = fopen("data.txt", "r");
    if(!fichero){
        printf("Error \n");
        return 1;
    }
    while(fgets(cadena, ELEMENTS_IN_LINE, fichero))
    {
        datoExtraido[idx] = atoi(cadena);
        idx++;
    }
    for(int i=0; i < ELEMENTS; i++){
        val_sum += datoExtraido[i];
        if (datoExtraido[i + 1] == 0){
            if (val_sum>max_val_sum)
            {
                max_val_sum2 = max_val_sum;
                max_val_sum = val_sum;
            }
            if(val_sum>max_val_sum2 && val_sum<max_val_sum){
                max_val_sum3 = max_val_sum2;
                max_val_sum2 = val_sum;
            }
            if(val_sum>max_val_sum3 && val_sum<max_val_sum2){
                max_val_sum3 = val_sum;
            }
            
            //max_val_sum = (val_sum>max_val_sum)?val_sum:max_val_sum;
            val_sum = 0;
        }
    }
    int total_cal = max_val_sum + max_val_sum2 + max_val_sum3;
    printf("%i \n", max_val_sum);
    printf("%i \n", max_val_sum2);
    printf("%i \n", max_val_sum3);
    printf("%i \n", total_cal);
    fclose(fichero);
    return 0;
}