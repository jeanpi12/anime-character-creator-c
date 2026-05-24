#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decision.h"
#include "jujutsu_kaisen.h"
#include "demon_slayer.h"
#include "hxh.h"


/*
static int ask_continue(void) {
    char choice[10];
    printf("Do you want to continue? (yes/no): ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0'; // Remove the newline character from the end of the string
    if (strcmp(choice, "yes") == 0) {
        return 1; // Continue
    } else if (strcmp(choice, "no") == 0) {
        return 0; // Exit
    } else {
        printf("Invalid choice. Please enter 'yes' or 'no'.\n");
        return ask_continue(); // Ask again
    }
}
*/

 int decision(void) {


    do {
    char world[200];


    printf("What world would you like to adventure in?\n");
    printf("Click 1 for Jujutsu Kaisen\n");
    printf("Click 2 for Demon Slayer\n");
    printf("Click 3 for Hunter x Hunter\n");
    fgets(world, sizeof(world), stdin);
    world[strcspn(world, "\n")] = '\0'; // Remove the newline character from the end of the string
    printf("You have chosen to adventure in: %s\n", world);

    if (strcmp(world, "1") == 0) {
        printf("You have chosen to adventure in Jujutsu Kaisen!\n");
        jujutsu_kaisen();

    } else if (strcmp(world, "2") == 0) {
        printf("You have chosen to adventure in Demon Slayer!\n");
        demon_slayer();

    } else if (strcmp(world, "3") == 0) {
        printf("You have chosen to adventure in Hunter x Hunter!\n");
        hxh();
    } else {
        printf("Invalid choice. Please choose a valid world.\n");
    } 

} while (1);

printf("Thank you for playing! Goodbye!\n");
    


    return EXIT_SUCCESS;

 }