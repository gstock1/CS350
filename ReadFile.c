#include <stdio.h>
#include <stdlib.h> 

struct Lab7_data {
	int x;
	float y;
	int z;
};

struct Lab7_data data[10];

int main(){

	FILE *datafile = fopen(datafile_name, "r");
	if (!datafile) {
 		printf("; open failed; program ends\n");
 		exit(EXIT_FAILURE);
 	}	

	for(int i = 0; i < 10; i++){

		fscanf(datafile,"%d", &x);
		fscanf(datafile, "%lf", &y);
		fscanf(datafile, "%d", &z);
		data[i] = (*&x, *&y, *&z);

	}

	fclose(datafile)

	return data;
}