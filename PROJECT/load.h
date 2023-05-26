# ifndef LINKEDLISTH
# define LINKEDLISTH

# include <stdio.h>
# include "linkedList.h"
# include <stdlib.h>



// Frame struct
typedef struct Frame
{
	char* name;
	unsigned int	duration;
	char* path;
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;



/*
	The function gets path and saves the project there.
	Input : head list.
	Output: None.
*/
void saveProject(FrameNode* head);


/*
	The function gets file path and loads the project from the file.
	Input : head list.
	Output: None.
*/
void loadProject(FrameNode** head);



# endif
