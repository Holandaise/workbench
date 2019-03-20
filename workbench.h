#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE ".data"
#define TITLE_MAX 100

typedef struct Note{
	unsigned int noteID;
	char title[TITLE_MAX];
	struct Note *next;
}Note;


// Initialize directory structure
void init(void);

// Create new note
void newNote(Note *head, char *title);

// Delete a note
void delNote(Note *head, unsigned int ID);

// Publish note
void publish(Note *n);

// List notes
void listNotes(Note *head);

// Get notes from file
Note *getNotes(void);

// Get a single note
Note *getNoteByID(Note *head, unsigned int ID);

// Write notes to file
void writeNotes(Note *head);

// Deallocate memory
void cleanup(Note *head);
