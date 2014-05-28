#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int won = 0;
    int i, j;
    int *doors;
    int choice;
    srand(time(0));
    for (i = 0; i < 1000000; i++) {
        doors = malloc(3*sizeof(int));
        for (j = 0; j < 3; j++) {
            doors[j] = 0;
        }
        doors[random()%3] = 1;
        choice = random()%3;
        for (j = 0; j < 3; j++) {
            if ( doors[j] == 0 && j != choice) {
                //monty opens door and player always swaps
                if ( j == 0 && choice == 1) {
                    choice = 2;
                }else if ( j == 1 && choice == 2) {
                    choice = 0;
                }else if ( j == 2 && choice == 0) {
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
