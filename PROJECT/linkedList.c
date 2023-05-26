# include "view.h"
# include <stdio.h>
# include <string.h>


# define STR_LEN 51

/*
	The function prints the frames in the list.
	Input : frames list(head).
	Output: None.
*/
void printFramesList(FrameNode* head)
{
	printf("Name\tDuration\tPath");

	while (head != NULL)
	{
		printf("%d\t%d ms\t%s", head->frame->name, head->frame->duration, head->frame->path);
		head = head->next;
	}
}


/*
	The function prints program menu and gets
	choice from the user.
	Input : None.
	Output: User choice.
*/
int getChoice()
{
	int choice = 0;

	printf("Enter choice: ");
	scanf("%d", &choice);

	return choice;
}


FrameNode* createNewFrame()
{
	int duration = 0;
	Frame* newFrame = NULL;
	FrameNode* newFrameNode = NULL;
	char path[STR_LEN] = { 0 };

	newFrame = (Frame*)malloc(sizeof(Frame));
	newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));

	printf("*** Creating new frame ***\n");
	printf("Please insert frame path:\n");
	sGets(path, STR_LEN);
	getchar();
}

/*
	The function insert the new frame at the end.
	Input : head, new person.
	Output: None.
*/
void insertFrameAtEnd(FrameNode** head, FrameNode* newFrame)
{
	if (!*head)
	{
		*head = newFrame;
	}
	else
	{
		FrameNode* p = *head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newFrame;
	}
}

/*
	The function gets string.
	Input : string, string length.
	Output: None.
*/
void sGets(char str[], int len)
{
	fgets(str, len, stdin);
	str[strcspn(str, "\n")] = 0;
}