#define _CRT_SECURE_NO_WARNINGS

# include "load.h"


# define STR_LEN 81
# define PATH 0
# define DURATION 1
# define NAME 2


/*
	The function gets path and saves the project there.
	Input : head list.
	Output: None.

	Save Format: path?duration?name;
*/
void saveProject(FrameNode* head)
{
	FILE* file = NULL;
	char fileName[STR_LEN] = { 0 };

	printf("Where to save the project? enter a full path and file name\n");
	sGets(fileName, STR_LEN);


	file = fopen(fileName, "w");

	if (file == NULL)
	{
		printf(" [ERROR] Folder does not exist\n");
	}
	else
	{
		while (head != NULL)
		{
			fprintf(file, "%s?%d?%s;", head->frame->path, head->frame->duration, head->frame->name);
			head = head->next;
		}

		fclose(file);
	}
	
}

/*
	The function gets file path and loads the project from the file.
	Input : head list.
	Output: None.
*/
void loadProject(FrameNode** head)
{
	Frame* newFrame = NULL;
	FrameNode* newFrameNode = NULL;
	int params = 0;
	FILE* file = NULL;
	char fileName[STR_LEN] = { 0 };
	char path[STR_LEN] = { 0 };
	char duration[STR_LEN] = { 0 };
	char name[STR_LEN] = { 0 };
	int ch = ' ';
	int param_loc = 0;

	printf("Enter the path of the project (including project name):\n");
	sGets(fileName, STR_LEN);
	file = fopen(fileName, "r");

	while (file == NULL)
	{
		printf("File does not exist, Enter the path of the project (including project name):\n");
		sGets(fileName, STR_LEN);
		file = fopen(fileName, "r");
	}

	// Maloc memory to the new frame
	newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));
	newFrame = (Frame*)malloc(sizeof(Frame));


	while ((ch = (char)fgetc(file)) != EOF)
	{
		if (ch == '?')
		{
			if (params == PATH)
			{
				newFrame->path = (char*)malloc(strlen(path) + 1);
				strcpy(newFrame->path, path); // Copy path
			}
			else if (params == DURATION)
			{
				newFrame->duration = atoi(duration);
			}

			params++;
			param_loc = 0;
		}
		else if (ch == ';')
		{
			if (params == NAME)
			{
				newFrame->name = (char*)malloc(strlen(name) + 1);
				strcpy(newFrame->name, name);
			}

			params = 0;
			param_loc = 0;
			
			// Create new frame
			newFrameNode->frame = newFrame;
			newFrameNode->next = NULL;
			insertFrameAtEnd(head, newFrameNode);
		}
		else
		{
			if (param_loc > STR_LEN)
			{
				printf("ERROR");
			}
			if (params == PATH)
			{
				path[param_loc] = ch;
			}
			else if (params == DURATION)
			{
				duration[param_loc] = ch;
			}
			else if (params == NAME)
			{
				name[param_loc] = ch;
			}
			param_loc++;
		}
	}

	fclose(file);

}