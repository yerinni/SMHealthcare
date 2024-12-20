//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    int loadExercises;
    
    Exercise exercises[100];
    int exercise_count = 0;
    loadExercises(EXERCISEFILEPATH, exercises, &exercise_count); // download the exercises from 'exercises.txt'

    Diet diets[100];
    int diet_count = 0;
    loadDiets(DIETFILEPATH, diets, &diet_count);  // download the diets from 'diets.txt'
    
    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	if (health_data.remaining_calories <= 0 ){
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	inputExercise(&health_data, exercises, exercise_count); //Run when user selects a exercise
                break;
                
            case 2:
            	inputDiet(&health_data, diets, diet_count); //Run when user selects a diet
                break;
                
            case 3:
            	printHealthData(&health_data);  //Run when a user wants to view information
                break;
                
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice !=4 && health_data.remaining_calories > 0); //Exit when the user has made 4 selections from the menu or has 0 calories remaining

    return 0;
}

