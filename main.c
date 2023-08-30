/*

Program 1: Elementary Cellular Automaton
course: CS 252, Fall 2023, UIC
System: VS Code
Author: Eduardo Morales

*/

#include <stdio.h>
#include <stdbool.h> 
#include <math.h>

const int WORLD_SIZE = 65;

typedef struct cell_struct{
    bool state[3]; //active status for [left, me, right] cells 
    bool active; //current active status for this cell
} cell;

//convert an 8-bit integer rule (0-255) to array of bits 
//(stored in reverse order)
//   ex: rule = 6  = 00000110 -> [01100000] 
//   ex: rule = 30 = 00011110 -> [01111000] 
//   ex: rule = 65 = 01000001 -> [10000010]
//return true if input rule is valid (0-255)
//return false if input rule is invalid
bool setBitArray(bool bitArray[8], int rule) {
	if (rule > 255 || rule < 0) 
		return false;
	int i = 0;
	while (rule > 0) {
		bitArray[i++] = rule % 2;
		rule /= 2;
	} 
	for (; i < 8; i++) {
		bitArray[i] = 0;
	}
	return true;
}

// This is a function I made to decompose the main function
// this will print out the evoluation state given a bitArray
// this can also be fleshed out to use later to store the evolution state
void printEvoState(bool bitArray[8]) {	
	printf("The evolution of all possible states are as follows:\n");
	printf("|***|   |** |   |* *|   |*  |   | **|   | * |   |  *|   |   |\n");

	for (int i = 7; i > -1; i--) {
		char c = (bitArray[i]) ? '*' : ' ' ;
		char *spacer = (i > 0) ? "    " : "";
		printf(" |%c|%s", c, spacer);
	} 

	printf("\n\n");
}


//convert a 3-bit state array to its 
//associated index of the rule# bit array
//   ex: {0 0 0} -> 0
//   ex: {0 0 1} -> 1
//   ex: {1 0 1} -> 5
int stateToIndex(bool state[3]) {
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		idx += state[i] * pow(2, 2 - i);
	}
	return idx;
}

//update the state array for each cell in the world array based on the
//current status of active for the nearby [left,me,right] cells
//note: world is assumed periodic/cyclic,
//with front-to-back and back-to-front wrapping 
void setStates(cell world[WORLD_SIZE]) {

    //TODO: Task 5 - write the setStates() function

    return;
}

//evolve each cell's active status to the next generation 
//  using its state array
//ruleBitArray contains the 8-bits for the rule#, 
//  stored in reverse order
void evolveWorld(cell world[WORLD_SIZE], bool ruleBitArray[8]) {

    //TODO: Task 7 - write the evolveWorld() function

    return;
}


int main() {
    cell world[WORLD_SIZE];
	int rule = -1;
	bool bitArray[8];

    printf("Welcome to the Elementary Cellular Automaton!\n");
	while (!setBitArray(bitArray, rule)) {
		printf("Enter the rule # (0-255): ");
		scanf("%d", &rule);
	}

	printf("\nThe bit array for rule #%d is ", rule);
	for (int i = 7; i > -1; i--)
		printf("%d", bitArray[i]);
	printf("\n\n");

	
    printEvoState(bitArray);

    //TODO: Task 6 - read in the total number of generation evolution 
    //      steps from the user and initialize the world with ONLY the 
    //      middle cell active, all other cells should be inactive; 
    //      make sure to set the state array for each cell.
    
    printf("Initializing world & evolving...\n");


    //TODO: Task 8 - evolve the world the user-specified number  
    //      of generations, printing each active cell as '*' and
    //      each non-active cell as ' ' (whitespace) after each
    //      evolution step to the next generation

    return 0;
}
