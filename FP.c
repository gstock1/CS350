

#include <stdio.h>
#include <stdlib.h> // For error exit()
#include "Struct.h"
int main(void) {
    printf("George Stock -- Lab7");
    struct Lab7_data data[100];
    char *datafile_name = "Lab7.txt";
    FILE *datafile = fopen(datafile_name, "r");
    for(int i = 0; i<100; i++){
        if (!datafile) {
            printf("; open failed; program ends\n");
            exit(EXIT_FAILURE);
        }
        else{
            int x1 = 0;
            float y1 = 0;
            int z1 = 0;
            
            fscanf(datafile, "%d", &x1);
            data[i].x = x1;
            fscanf(datafile, "%f", &y1);
            data[i].y;
            fscanf(datafile, "%d", &z1);
            data[i].z = z1;
        }
    }
    fclose(datafile);
    printf("\nThe x is: %d", data[0].x);
    printf("\nThe y is: %f", data[0].y);
    printf("\nThe z is: %d", data[0].z);
}