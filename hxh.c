#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hxh.h"


//==================Structures and Enums for Hunter x Hunter World====================
typedef enum {
    ENHANCEMENT,
    EMISSION,
    MANIPULATION,
    TRANSMUTATION,
    CONJURATION,
    SPECIALIZATION
} nen_type;


typedef struct {

    char name[200];
    nen_type type;
    int physical_strength;
    int agility;
    int intelligence;

}hunter;

//===========================================================================


// ==================Functions for Hunter x Hunter World====================

// Function to print a welcome message for the Hunter x Hunter world
static void welcome_message(void) {
    printf("Welcome to the world of Hunter x Hunter!\n");
    printf("In this world, you will embark on a journey to become a Hunter and face various challenges along the way.\n");
    printf("Let's create your Hunter!\n");
}


// Function to read the Hunter's Nen type from user input
static nen_type read_nen_type(void) {
    printf("Choose your Nen type:\n");
    printf("0: Enhancement\n");
    printf("1: Emission\n");
    printf("2: Manipulation\n");
    printf("3: Transmutation\n");
    printf("4: Conjuration\n");
    printf("5: Specialization\n");
    int nen_type_input;
    scanf("%d", &nen_type_input);
    getchar(); // Consume the newline character left by scanf
    nen_type type = (nen_type)nen_type_input;
    if (nen_type_input == 0) {
        printf("You have chosen Enhancement!\n");
    } else if (nen_type_input == 1) {
        printf("You have chosen Emission!\n");
    } else if (nen_type_input == 2) {
        printf("You have chosen Manipulation!\n");
    } else if (nen_type_input == 3) {
        printf("You have chosen Transmutation!\n");
    } else if (nen_type_input == 4) {
        printf("You have chosen Conjuration!\n");
    } else if (nen_type_input == 5) {
        printf("You have chosen Specialization!\n");
    } else {
        printf("Invalid choice. Please choose a valid Nen type.\n");
    }
    return type;

}


// Function to read the Hunter's physical strength from user input
    static void read_physical_strength(hunter *h) {
    printf("Enter the physical strength of your Hunter: ");
    scanf("%d", &h->physical_strength);
    getchar(); // Consume the newline character left by scanf
    printf("Your Hunter's physical strength is: %d\n", h->physical_strength);
}


//  Function to read the Hunter's agility from user input
static void read_agility(hunter *h) {
    printf("Enter the agility of your Hunter: ");
    scanf("%d", &h->agility);
    getchar(); // Consume the newline character left by scanf
    printf("Your Hunter's agility is: %d\n", h->agility);
}


// Function to read the Hunter's intelligence from user input
static void read_intelligence(hunter *h) {
    printf("Enter the intelligence of your Hunter: ");
    scanf("%d", &h->intelligence);
    getchar(); // Consume the newline character left by scanf
    printf("Your Hunter's intelligence is: %d\n", h->intelligence);
}

// Function to print Hunter information
static void print_hunter_info(const hunter *h) {
    printf("Hunter Name: %s\n", h->name);
    printf("Nen Type: ");
    switch (h->type) {
        case ENHANCEMENT:
            printf("Enhancement\n");
            break;
        case EMISSION:
            printf("Emission\n");
            break;
        case MANIPULATION:
            printf("Manipulation\n");
            break;
        case TRANSMUTATION:
            printf("Transmutation\n");
            break;
        case CONJURATION:
            printf("Conjuration\n");
            break;
        case SPECIALIZATION:
            printf("Specialization\n");
            break;
    }
    printf("Physical Strength: %d\n", h->physical_strength);
    printf("Agility: %d\n", h->agility);
    printf("Intelligence: %d\n", h->intelligence);
}





//=====================================================================

void hxh(void) {

    // Print a welcome message for the Hunter x Hunter world
    welcome_message();


    // Create a Hunter structure to store the user's Hunter information
    hunter my_hunter;


    // Read the Hunter's name from user input
    printf("What is your Hunter's name? ");
    fgets(my_hunter.name, sizeof(my_hunter.name), stdin);
    my_hunter.name[strcspn(my_hunter.name, "\n")] = '\0'; // Remove the newline character from the end of the string
    printf("Your Hunter's name is: %s\n", my_hunter.name);

    // Read the Hunter's Nen type from user input
    my_hunter.type = read_nen_type();

    // Read the Hunter's physical strength from user input
    read_physical_strength(&my_hunter);
    
    // Read the Hunter's agility from user input
    read_agility(&my_hunter);
    
    // Read the Hunter's intelligence from user input
    read_intelligence(&my_hunter);


}