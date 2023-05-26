# define CV_IGNORE_DEBUG_BUILD_GUARD
# include <opencv2/imgcodecs/imgcodecs_c.h>

# include <stdio.h>
# include "linkedList.h"
# include "view.h"
# include "load.h"


enum options {EXIT = 0, CREATE_FRAME, REMOVE_FRAME, CHANGE_FRAME_INDEX, CHANGE_FRAME_DUR, CHANGE_ALL_DUR, PRINT_LIST, PLAY_MOVIE, SAVE_PROJECT};


int main(void)
{
	int choice = -4;
	FrameNode* head = NULL;
	FrameNode* newFrame = NULL;
	int newDur = 0;
	int load = 0;

	
	printf("Welcome to Magshimim Movie Maker! what would you like to do?\n [0] Create a new project\n [1] Load existing project\n");
	scanf_s("%d", &load);
	getchar();

	if (load == TRUE)
	{
		loadProject(&head);
		printf("Project loaded successfully!\n");
	}

	while (choice != EXIT)
	{
		choice = getChoice();
		getchar();


		switch (choice)
		{
			case CREATE_FRAME:
				newFrame = createNewFrame(head);

				if (newFrame != NULL)
				{
					insertFrameAtEnd(&head, newFrame);
				}
				
				break;
			case REMOVE_FRAME:
				removeFrame(&head);

				break;
			case CHANGE_FRAME_INDEX:
				changeFrameIndex(&head);
				break;
			case CHANGE_FRAME_DUR:
				changeFrameDur(head);

				break;
			case CHANGE_ALL_DUR:
				// Gets new duration
				printf("Enter the duration for all frames: \n");
				scanf_s("%d", &newDur);
				getchar();

				changeAllFramesDur(head, newDur);

				break;
			case PRINT_LIST:
				printFramesList(head);

				break;
			case PLAY_MOVIE:
				play(head);

				break;
			case SAVE_PROJECT:
				saveProject(head);

				break;
			case EXIT:
				freeAllList(&head);
				printf("Bye!");
				break;
		}
	}

	getchar();
	return 0;
}
