
#include <stdio.h>
#include <math.h>
#include <strings.h>   // if you need string library
int main () {

	printf("CS 350 Lab 6 for %s\n\n", "George Stock");

	// Prompt for and read in the first hex integer value to process.
	//
	unsigned int val = 0;
    printf("Enter a value in hex (0 to quit): ");
	scanf("%x", &val);

	// Loop until the value to inxpect is zero.
	//
	while (val != 0) {
		int right_end, left_end;  // desired endpoints of substring
		char type;

		// Read the endpoints and selection type.  We initialize
		// to bad values in case the fscanf fails.
		//
		
		printf("Please enter right end point followed by left end point.");
		scanf("%x",&right_end);
		scanf("%x",&left_end);
		

		// If the endpoints are bad, complain and go on to the next value
		//
		if (left_end>right_end || left_end>31 || left_end<0 || right_end>31 || right_end<0){
		    printf("The end points are bad and I am complaining.");
		}
		
		

		// Otherwise process this input
		else {
		    int selection_length = right_end - left_end; 
		    int mask = (2<<selection_length) - 1;
		    mask = mask<<right_end;
		    printf("The mask is: %d\n",mask); // print mask to check it
		    

		    unsigned int selection = val & mask;
		    
		    selection = selection >> right_end;
			// Print val, the endpoints, and the selected bitstring
			printf("%x[%d:%d] = %x\n", val, left_end, right_end, selection);
		}
		printf("Let's go again.\n");
		printf("Enter a value in hex (0 to quit): ");
	    scanf("%x", &val);
	}
	printf("Quitting.\n");
	return 1;
}
