# ifndef LINKEDLISTH
# define LINKEDLISTH

# define FALSE 0
# define TRUE !FALSE

// Frame struct
typedef struct Frame
{
	char*		name;
	unsigned int	duration;
	char*		path;  
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

/*
	The function create new frame.
	Input : None.
	Output: New frame.
*/
FrameNode* createNewFrame();

/*
	The function insert the new frame at the end.
	Input : head, new person.
	Output: None.
*/
void insertFrameAtEnd(FrameNode** head, FrameNode* newFrame);
void deleteFrame(FrameNode* head, FrameNode* delFrame);
void deleteVideo(FrameNode* head);
int findByName(FrameNode* head, char* frameName);
void changeFrameLoc(FrameNode** head, FrameNode* frame, int newLoc);
void changeFrameLen(FrameNode* head, FrameNode* frame, int newLen);
void changeAllFramesLen(FrameNode* head, int newLen);

/*
	The function prints the frames in the list.
	Input : frames list(head).
	Output: None.
*/
void printFramesList(FrameNode* head);

/*
	The function prints program menu and gets
	choice from the user.
	Input : None.
	Output: User choice.
*/
int getChoice();

/*
	The function save to gif in file(txt format - name:time:path).
	Input: Frames, file.
	Output: None.
*/
void saveGif(FrameNode* head, FILE* file);

/*
	The function gets string.
	Input : string, string length.
	Output: None.
*/
void sGets(char str[], int len);

# endif
