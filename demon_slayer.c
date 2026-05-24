#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demon_slayer.h"



//==================Structures and Enums for Demon Slayer World====================
typedef enum {
    WATER_BREATHING,
    FIRE_BREATHING,
    THUNDER_BREATHING,
    WIND_BREATHING,
    STONE_BREATHING
} breathing_style;

typedef enum {
    NONE,
    PARTIAL,
    FULL
} demon_slayer_mark;


typedef struct {

    char name[200];
    breathing_style breathing_style;
    demon_slayer_mark mark;
    int physical_strength;
    int agility;
    int stamina;

}slayer;

//===========================================================================

//==================Functions for Demon Slayer World====================

// Function to print a welcome message for the Demon Slayer world
static void welcoming_message(void) {
    
    printf("Welcome to the world of Demon Slayer!\n");
    printf("In this world, you will face off against powerful demons and hone your skills as a demon slayer.\n");
    printf("Lets create your demon slayer!\n");

}
// Function to read the demon slayer's breathing style from user input
static breathing_style read_breathing_style(void) {
    printf("Choose your breathing style:\n");
    printf("0: Water Breathing\n");
    printf("1: Fire Breathing\n");
    printf("2: Thunder Breathing\n");
    printf("3: Wind Breathing\n");
    printf("4: Stone Breathing\n");
    int breathing_style_input;
    scanf("%d", &breathing_style_input);
    getchar(); // Consume the newline character left by scanf
    breathing_style style = (breathing_style)breathing_style_input;
    if (breathing_style_input == 0) {
        printf("You have chosen Water Breathing!\n");
    } else if (breathing_style_input == 1) {
        printf("You have chosen Fire Breathing!\n");
    } else if (breathing_style_input == 2) {
        printf("You have chosen Thunder Breathing!\n");
    } else if (breathing_style_input == 3) {
        printf("You have chosen Wind Breathing!\n");
    } else if (breathing_style_input == 4) {
        printf("You have chosen Stone Breathing!\n");
    } else {
        printf("Invalid choice. Please choose a valid breathing style.\n");
    }
    return style;
}


// Function to read the demon slayer's mark from user input
static demon_slayer_mark read_demon_slayer_mark(void) {
    printf("Choose your demon slayer mark:\n");
    printf("0: None\n");
    printf("1: Partial\n");
    printf("2: Full\n");
    int mark_input;
    scanf("%d", &mark_input);
    getchar(); // Consume the newline character left by scanf
    demon_slayer_mark mark = (demon_slayer_mark)mark_input;
    if (mark_input == 0) {
        printf("You have chosen no demon slayer mark.\n");
    } else if (mark_input == 1) {
        printf("You have chosen a partial demon slayer mark.\n");
    } else if (mark_input == 2) {
        printf("You have chosen a full demon slayer mark.\n");
    } else {
        printf("Invalid choice. Please choose a valid demon slayer mark.\n");
    }
    return mark;
}


// Function to read the demon slayer's physical strength from user input
static void read_physical_strength(slayer *s) {
    printf("Enter the physical strength of your demon slayer: ");
    scanf("%d", &s->physical_strength);
    getchar(); // Consume the newline character left by scanf
    printf("Your demon slayer's physical strength is: %d\n", s->physical_strength);
}


// Function to read the demon slayer's agility from user input
static void read_agility(slayer *s) {
    printf("Enter the agility of your demon slayer: ");
    scanf("%d", &s->agility);
    getchar(); // Consume the newline character left by scanf
    printf("Your demon slayer's agility is: %d\n", s->agility);
}


// Function to read the demon slayer's stamina from user input
static void read_stamina(slayer *s) {
    printf("Enter the stamina of your demon slayer: ");
    scanf("%d", &s->stamina);
    getchar(); // Consume the newline character left by scanf
    printf("Your demon slayer's stamina is: %d\n", s->stamina);
}


// Function to print the demon slayer's information
static void print_slayer_info(const slayer *s) {
    printf("Demon Slayer Information: \n");
    printf("Name: %s\n", s->name);
    printf("Breathing Style: ");
    switch (s->breathing_style) {
        case WATER_BREATHING:
            printf("Water Breathing\n");
            break;
        case FIRE_BREATHING:
            printf("Fire Breathing\n");
            break;
        case THUNDER_BREATHING:
            printf("Thunder Breathing\n");
            break;
        case WIND_BREATHING:
            printf("Wind Breathing\n");
            break;
        case STONE_BREATHING:
            printf("Stone Breathing\n");
            break;
    }
    printf("Demon Slayer Mark: ");
    switch (s->mark) {
        case NONE:
            printf("None\n");
            break;
        case PARTIAL:
            printf("Partial\n");
            break;
        case FULL:
            printf("Full\n");
            break;
    }
    printf("Physical Strength: %d\n", s->physical_strength);
    printf("Agility: %d\n", s->agility);
    printf("Stamina: %d\n", s->stamina);
}


//===========================================================================


// Main function for the Demon Slayer world
void demon_slayer(void) {

    welcoming_message();

    slayer my_slayer;
    
    // Read the name of the demon slayer from user input
    printf("Enter the name of your demon slayer: ");
    fgets(my_slayer.name, sizeof(my_slayer.name), stdin);
    my_slayer.name[strcspn(my_slayer.name, "\n")] = 0; // Remove newline character
    printf("Your demon slayer's name is: %s\n", my_slayer.name);

    my_slayer.breathing_style = read_breathing_style();
    my_slayer.mark = read_demon_slayer_mark();

    read_physical_strength(&my_slayer);
    read_agility(&my_slayer);
    read_stamina(&my_slayer);
    print_slayer_info(&my_slayer);


//breathing enum, mark enum, physical strength pointer, agility pointer, stamina pointer
}

