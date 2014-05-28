#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int won = 0;
    int i, j;
    int *doors;
    int choice;
    srand(time(NULL));
    for (i = 0; i < 1000000; i++) {
        doors = malloc(3*sizeof(int));
        for (j = 0; j < 3; j++) {
            //initialize to zero
            doors[j] = 0;
        }
        // put prize behind random door
        doors[random()%3] = 1;
        // choose a door
        choice = random()%3;
        for (j = 0; j < 3; j++) {
            if ( doors[j] == 0 && j != choice) {
                //monty opens door and player always swaps

                //closed | choice | closed
                if ( j == 0 && choice == 1) {
                    choice = 2;
                //closed | open | choice 
                }else if ( j == 1 && choice == 2) {
                    choice = 0;
                //choice | closed | open
                }else if ( j == 2 && choice == 0) {
                    choice = 1;
                //choice | open | closed 
                } else if ( j == 1 && choice == 0) {
                    choice = 2;
                //closed | choice | open
                } else if ( j == 2 && choice == 1) {
                    choice = 0;
                //open | closed | choice
                } else if ( j == 0 && choice == 2) {
                    choice = 1;
                }
                if (doors[choice] == 1) {
                    //You won!
                    won++;
                }
            }
        }
    }
    printf("won: %d\n", won);
    printf("You won %.3f percent of the time. You would have won %.3f percent of the time if you did not switch\n", won/10000.0, (100-won/10000.0));
}
