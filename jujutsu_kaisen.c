#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jujutsu_kaisen.h"





//============Structures and Enums for Jujutsu Kaisen World============

    // Grade of sorcerer
    typedef enum  {
        GRADE_FOUR,
        GRADE_THREE,
        SEMI_GRADE_ONE,
        GRADE_ONE,
        SPECIAL_GRADE
    } jjk_grade;


    // Affiliation of sorcerer
    typedef enum {
        Tokyo_Jujutsu_High,
        Kyoto_Jujutsu_High,
        Jujutsu_Society,
        Curse_User,
        Independent
    } jjk_affiliation;


    //Cursed Technique Structure
    typedef struct {
    char curse_name[200];
    char description[500];
    int cursed_energy_cost;
    int damage_potential;
    }cursed_technique;


// Sorcerer Structure
typedef struct  {
    
    //IDENTITY
    char name[200];
    jjk_grade grade;
    jjk_affiliation affiliation;

    //POWER & STATS
    int cursed_energy;
    int max_cursed_energy;
    int physical_power;
    int technique_power;


}sorcerer;

//===========================================================================

//=====================Functions for Jujutsu Kaisen World====================


//Welcome dialogue for Jujutsu Kaisen world
static void welcome_dialogue(void) {
    printf("Welcome to the world of Jujutsu Kaisen!\n");
    printf("In this world, sorcerers battle curses using their cursed energy and techniques.\n");
    printf("Let's create your own sorcerer and embark on an adventure!\n");
}


//Read the sorcerer's grade from user input
static jjk_grade read_sorcerer_grade(void) {
    printf("Now, let's choose your sorcerer's grade:\n");
    printf("0: Grade 4\n");
    printf("1: Grade 3\n");
    printf("2: Semi-Grade 1\n");
    printf("3: Grade 1\n");
    printf("4: Special Grade\n");
    int grade_input;
    scanf("%d", &grade_input);
    getchar(); // Consume the newline character left by scanf
    jjk_grade grade = (jjk_grade)grade_input;
    printf("You have chosen grade: %d\n", grade);
    return grade;
        }

//Read the sorcerer's affiliation from user input
static jjk_affiliation read_sorcerer_affiliation(void) {
    printf("Now, let's choose your sorcerer's affiliation:\n");
    printf("0: Tokyo Jujutsu High\n");
    printf("1: Kyoto Jujutsu High\n");
    printf("2: Jujutsu Society\n");
    printf("3: Curse User\n");
    printf("4: Independent\n");
    
    int affiliation_input;
    scanf("%d", &affiliation_input);
    getchar(); // Consume the newline character left by scanf
    jjk_affiliation affiliation = (jjk_affiliation)affiliation_input;

    if (affiliation_input == 0) {
        printf("You have chosen Tokyo Jujutsu High!\n");
    } else if (affiliation_input == 1) {
        printf("You have chosen Kyoto Jujutsu High!\n");
    } else if (affiliation_input == 2) {
        printf("You have chosen Jujutsu Society!\n");
    } else if (affiliation_input == 3) {
        printf("You have chosen Curse User!\n");
    } else if (affiliation_input == 4) {
        printf("You have chosen Independent!\n");
    } else {
        printf("Invalid choice. Please choose a valid affiliation.\n");
    }
    return affiliation;
}


//Read the sorcerer's cursed energy from user input
static void read_cursed_energy(sorcerer *s) {
    printf("Enter the current cursed energy of your sorcerer: ");
    scanf("%d", &s->cursed_energy);
    getchar(); // Consume the newline character left by scanf
    printf("Enter the maximum cursed energy of your sorcerer: ");
    scanf("%d", &s->max_cursed_energy);
    getchar(); // Consume the newline character left by scanf
    printf("Your sorcerer's current cursed energy is: %d\n", s->cursed_energy);
    printf("Your sorcerer's maximum cursed energy is: %d\n", s->max_cursed_energy);
}

//Read the sorcerer's physical power from user input
static void read_physical_power(sorcerer *s) {
    printf("Enter the physical power of your sorcerer: ");
    scanf("%d", &s->physical_power);
    getchar(); // Consume the newline character left by scanf
    printf("Your sorcerer's physical power is: %d\n", s->physical_power);
}



//Read the sorcerer's technique power from user input
static void read_technique_power(sorcerer *s) {
    printf("Enter the technique power of your sorcerer: ");
    scanf("%d", &s->technique_power);
    getchar(); // Consume the newline character left by scanf
    printf("Your sorcerer's technique power is: %d\n", s->technique_power);
}





// Function to print sorcerer information
static void print_sorcerer_info(const sorcerer *s) {
    printf("Sorcerer Information:\n");
    printf("Name: %s\n", s->name);
    printf("Grade: ");
    switch (s->grade) {
        case GRADE_FOUR:
            printf("Grade 4\n");
            break;
        case GRADE_THREE:
            printf("Grade 3\n");
            break;
        case SEMI_GRADE_ONE:
            printf("Semi-Grade 1\n");
            break;
        case GRADE_ONE:
            printf("Grade 1\n");
            break;
        case SPECIAL_GRADE:
            printf("Special Grade\n");
            break;
    }
    printf("Affiliation: ");
    switch (s->affiliation) {
        case Tokyo_Jujutsu_High:
            printf("Tokyo Jujutsu High\n");
            break;
        case Kyoto_Jujutsu_High:
            printf("Kyoto Jujutsu High\n");
            break;
        case Jujutsu_Society:
            printf("Jujutsu Society\n");
            break;
        case Curse_User:
            printf("Curse User\n");
            break;
        case Independent:
            printf("Independent\n");
            break;
    }
    printf("Cursed Energy: %d/%d\n", s->cursed_energy, s->max_cursed_energy);
    printf("Physical Power: %d\n", s->physical_power);
    printf("Technique Power: %d\n", s->technique_power);
    }






//=====================================================================

//================Main JUJUTSU KAISEN CODE================

void jujutsu_kaisen(void) {


    //welcome dialogue
    welcome_dialogue();

    //create a sorcerer and name
    sorcerer my_sorcerer;

    printf("Enter the name of your sorcerer: ");
    fgets(my_sorcerer.name, sizeof(my_sorcerer.name), stdin);
    my_sorcerer.name[strcspn(my_sorcerer.name, "\n")] = '\0'; // Remove the newline   
    printf("Your sorcerer's name is: %s\n", my_sorcerer.name);

    //read the sorcerer's grade
    my_sorcerer.grade = read_sorcerer_grade();

    //read the sorcerer's affiliation
    my_sorcerer.affiliation = read_sorcerer_affiliation();

    //read the sorcerer's cursed energy
    read_cursed_energy(&my_sorcerer);

    //read the sorcerer's physical power
    read_physical_power(&my_sorcerer);

    //read the sorcerer's technique power
    read_technique_power(&my_sorcerer);

    //print the sorcerer's information
    print_sorcerer_info(&my_sorcerer);


    

}