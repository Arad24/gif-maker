# define _CRT_SECURE_NO_WARNINGS
# include "menuFunc.h"
# include <stdio.h>


/*
	The function prints program menu and gets
	choice from the user.
	Input : None.
	Output: User choice.
*/
int getChoice()
{
	 // Random number
	int choice = -4;


	printf("What would you like to do?\n [0] Exit\n [1] Add new Frame\n [2] Remove a Frame\n [3] Change frame index\n [4] Change frame duration\n [5] Change duration of all frames\n [6] List frames\n [7] Play movie!\n [8] Save project\n");

	scanf("%d", &choice); // Get choice
	
	// Prints menu
	while (!(choice >= 0 && choice <= 8))
	{
		printf("ERROR - What would you like to do?\n [0] Exit\n [1] Add new Frame\n [2] Remove a Frame\n [3] Change frame index\n [4] Change frame duration\n [5] Change duration of all frames\n [6] List frames\n [7] Play movie!\n [8] Save project\n");

		scanf("%d", &choice); // Get choice
	}

	
	return choice;
}


/*
	The function prints welcome message and
	ask the client if he want to:
		0 - Create a new project.
		1 - Load existing project.
	Input : None.
	Output: User choice.
*/
int projectLoadChoice()
{
	int choice = 0;

	printf("Welcome to Magshimim Movie Maker! what would you like to do\n [0] Create a new project.\n [1] Load existing project.\n");
	scanf("%d", &choice);

	return choice;
}